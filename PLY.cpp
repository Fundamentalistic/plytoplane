#include "PLY.h"
#pragma warning(disable : 4996)

char * read_line_from_file(FILE* file, int* line_len)
{
	unsigned long long line_size = 128;
	char* line = (char*)malloc(line_size * sizeof(char));
	bzero(line, line_size * sizeof(char));
	char ch;
	int cursor = 0;
	while ((ch = fgetc(file)) != EOF) {
		line[cursor++] = ch;
		if (ch == '\n') {
			*line_len = cursor;
			return line;
		}
		if (cursor >= line_size) {
			line = (char*)realloc(line, line_size * 2 * sizeof(char));
			line_size = line_size * 2;
		}
	}
	*line_len = cursor;
	return line;
}


char* get_word_after_n_space(char* line, int* line_len, int space_n)
{
	int space_counter = 0;
	int word_cursor = 0;
	int word_size = 30;
	char* word = (char*)malloc(sizeof(char) * word_size);
	bzero(word, sizeof(char) * word_size);
	for (int i = 0; i < *line_len; i++) {
		if (line[i] == ' ') {
			space_counter++;
			continue;
		}
		if (space_counter < space_n) {
			continue;
		}
		word[word_cursor++] = line[i];
		if (word_cursor >= word_size) {
			word_size = word_size * 2;
			word = (char*)realloc(word, sizeof(char) * word_size);
		}
	}
	return word;
}


void parse_coordinates(char* line, int* line_len, int* x, int* y, int* z)
{
	char * cx = (char*)malloc(sizeof(char) * 30);
	char * cy = (char*)malloc(sizeof(char) * 30);
	char * cz = (char*)malloc(sizeof(char) * 30);
	bzero(cx, 30); bzero(cy, 30); bzero(cz, 30);
	int cursor = 0;
	int statement = 0;
	for (int i = 0; i < *line_len; i++) {
		switch (statement) {
		case 0:
			cx[cursor++] = line[i];
			break;
		case 1:
			cy[cursor++] = line[i];
			break;
		case 2:
			cz[cursor++] = line[i];
			break;
		}
		if (line[i] == ' ') {
			statement++;
		}
	}
	*x = atoi(cx);
	*y = atoi(cy);
	*z = atoi(cz);
}


PLY* read_ply_file(const char* path)
{
	int points_number;
	int faces_number;
	int points_is_readed = 0;
	int cursor = 0;
	int face_cursor = 0;
	int header_is_readed = 0;
	PLY* ply = (PLY*)malloc(sizeof(PLY));
	bzero(ply, sizeof(PLY*));
	if (!ply) {
		printf("ERROR: Insuficient memory");
		exit(1);
	}
	FILE * file = fopen(path, "r");
	if (!file) {
		printf("Error when file reading: %s\n", path);
		exit(1);
	}
	int line_len = -1;
	while (line_len != 0) {
		char* line = read_line_from_file(file, &line_len);
		if (line_len > 10 && strstr(line, "end_header") != NULL) {
			header_is_readed = 1;
			continue;
		}
		if (strstr(line, "element vertex") != NULL) {
			char* points_number_string = get_word_after_n_space(line, &line_len, 2);
			points_number = atoi(points_number_string);
			free(points_number_string);
			printf("Points number: %i\n", points_number);
			ply->content = (PLYPoint**)malloc(sizeof(PLYPoint*) * points_number);
			bzero(ply->content, sizeof(PLYPoint*) * points_number);
			for (int i = 0; i < points_number; i++) {
				ply->content[i] = new PLYPoint;
			}
			if (!ply->content) {
				printf("ERROR: Insuficient memory");
				exit(1);
			}
			ply->content_length = points_number;
		}
		if (strstr(line, "element face") != NULL) {
			char* faces_number_string = get_word_after_n_space(line, &line_len, 2);
			faces_number = atoi(faces_number_string);
			ply->faces_length = faces_number + 1;
			ply->faces = (FACE**)malloc(sizeof(FACE*) * faces_number);
			bzero(ply->faces, sizeof(FACE*) * faces_number);
			for( int i = 0; i < ply->faces_length; i++ ){
				ply->faces[i] = new FACE;
			}
			free(faces_number_string);
			printf("Faces number: %i\n", faces_number);
		}
		if (header_is_readed && !points_is_readed) {
			char* token = strtok(line, " ");
			int cur = 0;
			ply->content[cursor]->x = atoi(token);
			token = strtok(NULL, " ");
			ply->content[cursor]->y = atoi(token);
			token = strtok(NULL, " ");
			ply->content[cursor]->z = atoi(token);
            token = strtok(NULL, " ");
            ply->content[cursor]->c.r = (unsigned char)atoi(token);
            token = strtok(NULL, " ");
            ply->content[cursor]->c.g = (unsigned char)atoi(token);
            token = strtok(NULL, " ");
            ply->content[cursor]->c.b = (unsigned char)atoi(token);
			// token = strtok(NULL, " ");
			// ply->content[cursor]->is_contact_point = (char)atoi(token);
			// std::cout << "color: " << (int)ply->content[cursor]->c.r << ":"
			// << (int)ply->content[cursor]->c.g << ":"
			// << (int)ply->content[cursor]->c.b << std::endl;
			cursor++;
			if (cursor == points_number) {
				points_is_readed = 1;
				continue;
			}
		}
		if (header_is_readed && points_is_readed && line_len != 0) {

			char* token = strtok(line, " ");
			token = strtok(NULL, " ");
			int p1 = atoi(token);
			token = strtok(NULL, " ");
			int p2 = atoi(token);
			token = strtok(NULL, " ");
			int p3 = atoi(token);

            unsigned char r = (unsigned char)atoi(token);
            token = strtok(NULL, " ");
            unsigned char g = (unsigned char)atoi(token);
            token = strtok(NULL, " ");
            unsigned char b = (unsigned char)atoi(token);

			ply->faces[face_cursor]->face_id = face_cursor;
			ply->faces[face_cursor]->point_ids.push_back(p1);
			ply->faces[face_cursor]->point_ids.push_back(p2);
			ply->faces[face_cursor]->point_ids.push_back(p3);

			ply->content[p1]->links.insert(p2);
			ply->content[p1]->links.insert(p3);

			ply->content[p2]->links.insert(p1);
			ply->content[p2]->links.insert(p3);
			
			ply->content[p3]->links.insert(p1);
			ply->content[p3]->links.insert(p2);

			ply->content[p1]->faces.insert(face_cursor);
			ply->content[p2]->faces.insert(face_cursor);
			ply->content[p3]->faces.insert(face_cursor);

			face_cursor++;
		}

		free(line);
	}
	return ply;
}


RAWPLY* read_ply_file_to_raw(const char* path, int target_id)
{
	int points_number;
	int faces_number;
	int points_is_readed = 0;
	int cursor = 0;
	int faces_cursor = 0;
	int header_is_readed = 0;
	RAWPLY* res = (RAWPLY*)malloc(sizeof(RAWPLY));
	if (!res) {
		printf("ERROR: Insuficient memory");
		exit(1);
	}
	FILE * file = fopen(path, "r");
	if (!file) {
		printf("Error when file reading: %s\n", path);
		exit(1);
	}
	int line_len = -1;
	while (line_len != 0) {
		char* line = read_line_from_file(file, &line_len);
		if (line_len > 10 && strstr(line, "end_header") != NULL) {
			header_is_readed = 1;
			continue;
		}
		if (strstr(line, "element vertex") != NULL) {
			char* points_number_string = get_word_after_n_space(line, &line_len, 2);
			points_number = atoi(points_number_string);
			free(points_number_string);
			printf("Points number: %i\n", points_number);
			res->points = (PLYPoint**)malloc(sizeof(PLYPoint*) * points_number);
			for (int i = 0; i < points_number; i++) {
				res->points[i] = new PLYPoint;
			}
			if (!res->points) {
				printf("ERROR: Insuficient memory");
				exit(1);
			}
			res->points_length = points_number;
		}
		if (strstr(line, "element face") != NULL) {
			char* faces_number_string = get_word_after_n_space(line, &line_len, 2);
			faces_number = atoi(faces_number_string);
			free(faces_number_string);
			printf("Faces number: %i\n", faces_number);
			res->faces_length = faces_number;
			res->faces = (FACE**)malloc(sizeof(FACE*) * faces_number);
			for (int i = 0; i < faces_number; i++) {
				res->faces[i] = new FACE;
			}
		}
		if (header_is_readed && !points_is_readed) {
			char* token = strtok(line, " ");
			int cur = 0;
			res->points[cursor]->x = atoi(token);
			token = strtok(NULL, " ");
			res->points[cursor]->y = atoi(token);
			token = strtok(NULL, " ");
			res->points[cursor]->z = atoi(token);
			cursor++;
			if (cursor == points_number) {
				points_is_readed = 1;
				continue;
			}
		}
		if (header_is_readed && points_is_readed && line_len != 0) {

			char* token = strtok(line, " ");
			res->faces[faces_cursor]->face_length = atoi(token);
			for (int i = 0; i < res->faces[faces_cursor]->face_length; i++) {
				token = strtok(NULL, " ");
				int pid = atoi(token);
				res->faces[faces_cursor]->point_ids.push_back(pid);
			}
			faces_cursor++;
		}

		free(line);
	}
	return res;
}


void fill_neighbour_faces(PLY * ply, FACE * target_face)
{
	std::map<int, int> et;

	for( int pid: target_face->point_ids ){
		for( int f: ply->content[pid]->faces ){
			if( et.find(f) == et.end() ){
				et[f] = 1;
			}else{
				et[f]++;
			}
		}
	}

	for( auto &el: et ){
		if(el.second == 2){
			target_face->neighbours.push_back(el.first);
		}
	}
}


double distance(PLYPoint * p1, PLYPoint * p2)
{
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
}


double angle(point * v1, point * v2)
{
	double divident = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	double divider = sqrt(pow(v1->x, 2) + pow(v1->y, 2) + pow(v1->z, 2)) * sqrt(pow(v2->x, 2) + pow(v2->y, 2) + pow(v2->z, 2));
	double angle = divident / divider; // in RAD
	return angle;
}