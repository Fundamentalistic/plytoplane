#ifdef _WIN32
#include <Windows.h>
#define bzero ZeroMemory
#endif
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include "PSBColors/PSBColors.h"

typedef struct {
	double x;
	double y;
    color c;
	unsigned int index;
	unsigned int global_index;
	double distance_from_center;
	char is_contact_point;
} Point2D;

typedef struct {
	unsigned int a;
	unsigned int b;
	unsigned int c;
} Triangle;

typedef struct {
    Point2D p;
    color c;
} PlanePoint;

typedef struct {
	int x;
	int y;
	int z;
	std::set<int> links;
	std::set<int> faces;
	Point2D pp;
    color c;
	char is_contact_point;
} PLYPoint;

typedef struct {
	int face_length;
	int proceeded;
	unsigned int face_id;
	std::vector<int> point_ids;
	std::vector<int> neighbours;
	Point2D pp1;
	Point2D pp2;
	Point2D pp3;
	unsigned int d_ic;
} FACE;

typedef struct {
	PLYPoint ** content;
	FACE** faces;
	int content_length;
	int faces_length;
} PLY;

typedef struct {
	int points_length;
	int faces_length;
	PLYPoint** points;
	FACE** faces;
} RAWPLY;

typedef struct {
	double x;
	double y;
	double z;
} point;


PLY * read_ply_file(const char* path);
RAWPLY* read_ply_file_to_raw(const char* path, int target_id);
void fill_neighbour_faces(PLY * ply, FACE * target_face);
double distance(PLYPoint * p1, PLYPoint * p2);
double angle(point * v1, point * v2);