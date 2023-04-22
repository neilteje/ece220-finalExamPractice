#include "polygon.h"

int main(int argc, char *argv[])
{
    char* input_file;
    char* output_file;
    vertex* vertices = NULL; /* list of vertices */
    int ret = 0;             /* holds return value
                                (1 success, 0 failure) */

    int n = 0;              /* number of vertices */
    float perimeter = 0.0;  /* results of calculations */

    /* Get file names */
    if(argc < 3)
    {
        printf("Usage: ./program4 inputfile outputfile\n");
        return 0;
    }
    input_file = argv[1];
    output_file = argv[2];

    /* Read from input file */
    vertices = read_polygon(input_file, &n);
    if (vertices == NULL)
    {
        printf("Error while reading file %s\n", input_file);
        return 0;
    }

    /* Perform calculations */
    perimeter = calc_perimeter(vertices, n);

    /* Display calculation results on screen */
    printf("The calculated perimeter is %.2f\n", perimeter);

    /* Write to output file */
    ret = record_polygon(output_file, vertices, n, perimeter);
    if (ret == 0)
    {
        printf("Error while writing file %s\n", output_file);
        return 0;
    }

    return 1;
}

