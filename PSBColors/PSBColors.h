#ifndef PSB_COLORS
#define PSB_COLORS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <map>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

typedef struct {
    char key[5];
    color value;
} color_key_value_pair;

typedef struct {
    unsigned int length;
    color * array;
} colors_array;

extern std::map<std::string, color> color_map;
extern int colors_array_is_initialized;
extern int random_is_initialized;
extern colors_array colors;

color generate_random_color();
int save_colors_array();
void initiate_colors_array();
void initiate_start_variables();
bool check_if_color_already_exists(color test);
color get_color_or_generate_new(std::string atom_name);
#endif