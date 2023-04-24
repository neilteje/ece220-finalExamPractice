#include "polygon.h"
#include<math.h>

/* This function should read the number of vertices record from the file with the supplied file_name,
     allocate memory for the vertex array, and populate the array with data read from the file.
   Note that only x and y fields need to be populated by this function.
   The function should return a pointer to the populated array of vertex records and the number of read records in count.
   If the function fails to read data from the file, it should return NULL and count should be set to 0.
   INPUT:
        file_name: name of the input file located in the local directory
        count: pointer to an int for holding the number of vertices
   OUTPUTS:
        count: holds the number of vertices
   RETURN:        
        pointer to allocated and populated vertex array
        (NULL if read failure)
*/
vertex* read_polygon(char *file_name, int *count)
{
    FILE* myfile = fopen(file_name, "r");
    if (!myfile) {
        *count = 0;
        return NULL; //failed to read file
    }
    char newl;
    fscanf(myfile, "%d", count);
    fscanf(myfile, "%c", &newl); //taken vertex count
    int numofv = *count;    //convenient variable
    //creating a 2D array to store vertices
    vertex** verticesarray = (vertex**)malloc(numofv*sizeof(vertex));
    for (int i = 0; i<numofv; i++){
        int* x;
        int* y;
        fscanf(myfile, "%d %d", x, y);
        fscanf(myfile, "%c", &newl);
        verticesarray[i] = (vertex*)malloc(sizeof(vertex));
        verticesarray[i]->x = *x;
        verticesarray[i]->y = *y;
    }
    fclose(myfile);
    return verticesarray;
}

/* This function should calculate length of each side of the polygon as well as the polygon’s perimeter.
   The length of polygon’s side is computed as sqrt((x2-x1)^2 + (y2-y1)^2),
   This value should be stored in the length field for polygon with coordinates (x1, y1).
   Perimeter is computed by finding the sum of all side lengths of the polygon.
   This value should be computed and returned by the function.
   INPUT:
        vrtx: pointer to an array of vertices
        count: the length of the vertex array
   OUTPUTS:
        length field of each vertex calculated
   RETURN:        
        calculated perimeter
*/
float calc_perimeter(vertex* vrtx, int count)
{
    if (!vrtx) return 0.0f;
    float perimeter = 0;
    int x1, y1, x2, y2;
    float sidelength;
    for (int i = 0; i<count-1; i++){
        x1 = vrtx[count]->x;
        y1 = vrtx[count]->y;
        x2 = vrtx[count+1]->x;
        y2 = vrtx[count+2]->y;
        sidelength = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        vrtx[count]->length = sidelength;
        perimeter += sidelength;
    }
    x1 = vrtx[0]->x;
    y1 = vrtx[0]->y;
    x2 = vrtx[count-1]->x;
    y2 = vrtx[count-1]->y;
    sidelength = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    vrtx[count-1]->length = sidelength;
    perimeter += sidelength;
    return perimeter;
}

/* This function should write to file file_name the number of vertices record followed by records
     for each vertex consisting of the space-separated x, y, and length fields, followed by the perimeter.
   The function should also free memory allocated for vertex array.
   It should return 1 if the data is successfully stored in the output file, or 0 otherwise.
   INPUT:
        file_name: name of the output file
        vrtx: pointer to an array of vertices
        count: the length of the vertex array
        perimeter: the perimeter of the polygon
   OUTPUTS:
        data is written to file_name
   RETURN:        
        1 if file successfully written and vertix freed
        0 otherwise
*/
int record_polygon(char *file_name, vertex *vrtx, int count, float perimeter)
{
    if (!vrtx) return 0;
    FILE* myfile = fopen(file_name, "w");
    char newl = '\n';
    fprintf(myfile, "%d", count);
    fprintf(myfile, "%c", newl);
    int x, y;
    float sidelength;
    for (int i = 0; i<count; i++){
        fprintf(myfile, "%d %d %f", vrtx[count]->x,vrtx[count]->y;vrtx[count]->length);
        fprintf(myfile, "%c", newl);
    }
    fprintf(myfile, "%f", perimeter);
    fprintf(myfile, "%c", newl);
    fclose(myfile);
    return 1;
}
