#include <iostream>
#include "PLY.h"

int main(int argc, char * argv[])
{
    const char * ply_file_path = "1cd0.ply";
    PLY * content = read_ply_file(ply_file_path);
    printf("PLY READING RESULTS: \n");
    printf("content_length: %i\n", content->content_length);
    printf("faces_length: %i\n", content->faces_length);
    return 0;
}