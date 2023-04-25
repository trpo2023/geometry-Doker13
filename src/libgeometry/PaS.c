#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/PaS.h>

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

double square(double r)
{
    double p = 2 * M_PI * r;
    return p;
}

double perimetr(double r)
{
    double s = M_PI * r * r;
    return s;
}

int intersect(
        double x, double y, double r, double comx, double comy, double comr)
{
    double dist, distx, disty;
    distx = x - comx;
    disty = y - comy;
    if (distx < 0) {
        distx = distx * -1;
    }
    if (disty < 0) {
        disty = disty * -1;
    }
    dist = sqrt((distx * distx) + (disty * disty));
    if (dist <= comr + r) {
        return 1;
    }
    return 0;
}
