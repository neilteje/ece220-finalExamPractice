#include "polygon.h"

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
     FILE *fptr = fopen(file_name, "r");
     if (fptr == NULL) {
          *count = 0;
          return NULL;
     }
     fscanf(fptr, "%d", count);
     vertex *vrtx = (vertex*)malloc(*count * sizeof(vertex));
     for (int i = 0; i < *count; i++) {
          fscanf(fptr, "%d %d", &vrtx[i].x, &vrtx[i].y);
     }
     fclose(fptr);
     return vrtx;
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
     float perimeter = 0;
     for (int i = 0; i < count; i++) {
          int j = (i + 1) % count;
          float dx = vrtx[j].x - vrtx[i].x;
          float dy = vrtx[j].y - vrtx[i].y;
          vrtx[i].length = sqrt(dx*dx + dy*dy);
          perimeter += vrtx[i].length;
     }
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
    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL) {
        return 0;
    }
    fprintf(fptr, "%d", count);
    for (int i = 0; i < count; i++) {
        fprintf(fptr, " %d %d %.2f", vrtx[i].x, vrtx[i].y, vrtx[i].length);
    }
    fprintf(fptr, " %.2f", perimeter);
    fclose(fptr);
    free(vrtx);
    return 1;
}
