from PIL import Image
import numpy as np
import re

filepath = '../1fvm.ply'
file = open(filepath, 'r')
lines = file.readlines()
points = None
points_len = None
spoints = None
isVertexScope = False;
vertex_counter = 0

for id, line in enumerate(lines):
    if line.find('element vertex') != -1:
        points_len = int(line.split( )[2])
        points = np.zeros((points_len, 4))
        spoints = np.zeros((points_len, 4))
    elif line.find('end_header') != -1:
        isVertexScope = True
        continue

    if isVertexScope:
        sp = re.split(r'[ ]+', line)
        x = float(sp[0])
        y = float(sp[1])
        z = float(sp[2])
        c = int(sp[3]) * int(sp[4]) + int(sp[5])
        points[vertex_counter, 0] = x
        points[vertex_counter, 1] = y
        points[vertex_counter, 2] = z
        points[vertex_counter, 3] = c
        vertex_counter += 1
        if vertex_counter == points_len:
            break


points[:, 3] /= points[:, 3].max()
points[:, 3] *= 255
spoints[:, 0] = np.sqrt(np.power(points[:, 0], 2) + np.power(points[:, 1], 2) + np.power(points[:, 2], 2))
spoints[:, 1] = np.arccos(points[:, 2] / spoints[:, 0])
spoints[:, 2] = np.arctan(points[:, 1] / points[:, 0])
spoints[:, 3] = points[:, 3]

spoints[:, 0:3] *= 10
spoints *= 10

spoints = spoints.astype(np.uint32)

image_size = (
    (spoints[:, 1].max() - spoints[:, 1].min()) + 200,
    (spoints[:, 2].max() - spoints[:, 2].min()) + 200,
)

spoints[:, 1] -= spoints[:, 1].min()
spoints[:, 2] -= spoints[:, 2].min()


image = np.zeros(image_size, dtype=np.uint8)

for i in range(spoints.shape[0]):
    image[spoints[i, 0], spoints[i, 1]] = spoints[i, 3]

im = Image.fromarray(image)
im.show()