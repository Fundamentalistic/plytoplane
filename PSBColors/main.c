#include <stdio.h>
#include <stdlib.h>
#include "PSBColors.h"
#include "../HexDump/HexDump.h"

int main()
{
    initiate_start_variables();
    initiate_colors_array();
    printf("Colors test system\n");

    for( int i = 0; i < colors.length; i++ ){
        printf("R: %i G: %i B: %i\n", 
            colors.array[i].r, 
            colors.array[i].g, 
            colors.array[i].b
        ); 
    }

    colors_array_is_initialized = 1;

    color c1 = {10, 30, 50};
    color c2 = {20, 40, 60};
    color c3 = {30, 60, 70};

    colors.length = 3;
    colors.array = (color*)malloc(sizeof(color)*colors.length);
    colors.array[0].r = c1.r;
    colors.array[0].g = c1.g;
    colors.array[0].b = c1.b;
    colors.array[1].r = c2.r;
    colors.array[1].g = c2.g;
    colors.array[1].b = c2.b;
    colors.array[2].r = c3.r;
    colors.array[2].g = c3.g;
    colors.array[2].b = c3.b;

    hexDump("colors.array[0]: ", &colors.array[0], sizeof(color), 32);
    hexDump("colors.array[1]: ", &colors.array[1], sizeof(color), 32);
    hexDump("colors.array[2]: ", &colors.array[2], sizeof(color), 32);
    hexDump("colors.array[0] * 3: ", &colors.array[0], sizeof(color) * 3, 32);

    printf("%i %i %i\n", c1.r, c1.g, c1.b);
    printf("%i %i %i\n", c2.r, c2.g, c2.b);
    printf("%i %i %i\n", c3.r, c3.g, c3.b);

    save_colors_array();

    return 0;
}