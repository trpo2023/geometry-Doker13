#include <libgeometry/PaS.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double x_reader(char* str)
{
    char strx[20];
    int j = 0;
    int i = 1;
    while (str[i] != ' ') {
        strx[j] = str[i];
        i++;
        j++;
    }
    strx[j] = '\0';
    double x = atof(strx);
    return x;
}

double y_reader(char* str)
{
    char stry[20];
    int j = 0;
    int i = 1;
    while (str[i] != ' ') {
        i++;
    }
    while (str[i] != ',') {
        stry[j] = str[i];
        j++;
        i++;
    }
    stry[j] = '\0';
    double y = atof(stry);
    return y;
}

double r_reader(char* str)
{
    char strr[20];
    int j = 0;
    int i = 1;
    while (str[i] != ',') {
        i++;
    }
    i++;
    while (str[i] != ')') {
        strr[j] = str[i];
        j++;
        i++;
    }
    strr[j] = '\0';
    double r = atof(strr);
    return r;
}

int square(double r)
{
    int p = 2 * M_PI * r;
    return p;
}

int perimetr(double r)
{
    int s = M_PI * r * r;
    return s;
}
