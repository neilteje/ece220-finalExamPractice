#ifndef POLYGON_H
#define POLYGON_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int x, y;     /* vertex coordinates */
    float length; /* polygon’s side length */
} vertex;


vertex* read_polygon(char *file_name, int *count);

float calc_perimeter(vertex* vrtx, int count);

int record_polygon(char *file_name, vertex *vrtx, int count, float perimeter);

#endif
