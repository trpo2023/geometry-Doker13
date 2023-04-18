#include <stdio.h>
#pragma once

typedef struct circle {
    double x;
    double y;
    double R;
} circle;

double x_reader(char* str);
double y_reader(char* str);
double r_reader(char* str);
int square(double r);
int perimetr(double r);
