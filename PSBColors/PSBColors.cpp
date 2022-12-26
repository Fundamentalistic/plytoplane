#include "PSBColors.h"
#include <string>
#include <fstream>


// ToDO: Выполнить доработку сохранения цветов и их восстановления и файла

std::map<std::string, color> color_map;
colors_array colors;
int colors_array_is_initialized;
int random_is_initialized;


char * read_line(FILE * file, unsigned int *line_len) 
{
    char * line;
    unsigned int start_position = ftell(file);
    unsigned int break_line_position = 0;
    unsigned int line_cursor = 0;
    *line_len = -1;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if ( ch == '\n' ) {
            break_line_position = ftell(file);
            *line_len = break_line_position - start_position;
            fseek(file, start_position, SEEK_SET);
            line = (char*)malloc(*line_len + 1);
#ifndef _WIN32
            bzero(line, *line_len + 1);
#else
            ZeroMemory(line, *line_len + 1);
#endif
            break;
        }
    }

    while ((ch = fgetc(file)) != EOF) {
        line[line_cursor] = ch;
        line_cursor++;
        if ( ch == '\n' ) {
            return line;           
        }
    }
    return NULL;
}

char ** file_read_lines(const char * path, unsigned int * lines_counter)
{
    printf("PATH: %s\n", path);
    FILE * file = fopen(path, "r");
    unsigned int lines_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if ( ch == '\n') {
            lines_count++;
        }
    }
    fseek(file, 0, SEEK_SET);
    printf("Lines count: %i\n", lines_count);
    *lines_counter = lines_count;
    char ** lines = (char **)malloc(lines_count * sizeof(char**));
    
    unsigned int line_len = 0;
    unsigned int line_cursor = 0;

    while (line_len != -1) {
        lines[line_cursor] = read_line(file, &line_len);
        line_cursor++;
    }

    std::cout << "test" << std::endl;

    // fclose(file);
    std::cout << "test" << std::endl;
    return lines;
}

bool check_if_color_already_exists(color test)
{
    for( int i = 0; i < colors.length; i++ ){
        if(
            test.r == colors.array[i].r &&
            test.g == colors.array[i].g &&
            test.b == colors.array[i].b
        ){
            return true;
        }
    }
    return false;
}

color generate_random_color()
{
    if(!random_is_initialized){
        random_is_initialized = 1;
        srand(time(NULL));
    }
    color c;
    c.r = rand() * 255;
    c.g = rand() * 255;
    c.b = rand() * 255;
    return check_if_color_already_exists(c) ? generate_random_color() : c;
}

color get_color_or_generate_new(std::string atom_name)
{

    color res;

    if( color_map.find(atom_name) != color_map.end() ){
        res = color_map[atom_name];
    } else {
        res = generate_random_color();
        color_map[atom_name] = res;
    }

    return res;
}

void initiate_start_variables()
{
    colors_array_is_initialized = 1;
}


void initiate_colors_array()
{
    unsigned int lines_counter = 0;
    char ** file_lines = file_read_lines("colors.b", &lines_counter);
    for( unsigned int i = 0; i < lines_counter; i++ ) {
        char * line = file_lines[i];
        char * atom_name = strtok(line, ":");
        char * r = strtok(NULL, ":");
        char * g = strtok(NULL, ":");
        char * b = strtok(NULL, ":");
        color c = {(unsigned char)atoi(r), (unsigned char)atoi(g), (unsigned char)atoi(b)};
        color_map[atom_name] = c;

    }
    colors_array_is_initialized = 1;
}


int save_colors_array()
{

    if( !colors_array_is_initialized ){
        printf("Unable to save uninitialized colors array");
        return 0;
    }

    std::ofstream colors_file("colors.b", std::ios::out);
    if(!colors_file.is_open()){
        printf("Unable to open colors file. ERRNO: <%i>\n", errno);
        return 0;
    }

    printf("colors.length = %u\n", color_map.size()); 
    
    for( auto& c: color_map ){
        color clr = c.second;
        colors_file << c.first << ":" << (int)clr.r << ":" << (int)clr.g << ":" << (int)clr.b << std::endl;
    }

    colors_file.close();



    return 1;

}
