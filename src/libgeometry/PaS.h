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
double square(double r);
double perimetr(double r);
int intersect(
	double x, double y, double r, double comx, double comy, double comr);
