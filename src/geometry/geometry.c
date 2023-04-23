#include <libgeometry/PaS.h>
#include <libgeometry/parser.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* file = "input.txt";
    FILE* fp = fopen(file, "r");
    if (!fp) {
        printf("File not found\n");
        return -1;
    }
    char get[100];
    int counter = 0;
    while (fgets(get, 100, fp) != NULL) {
        counter++;
    }
    fseek(fp, 0, SEEK_SET);
    circle* figur[counter];
    char str[100];
    char circ[20];
    int circlescount = 0;
    while (fscanf(fp, "%s ", circ) == 1) {
        fgets(str, 100, fp);
        circle* circles = (circle*)malloc((sizeof(double) * 3));
        if (word_check(circ, str)==0 || first_bkt_check(circ, str)==0 || second_bkt_check(circ, str)==0 || arguments_check(circ, str)==0 || range_check(circ, str)==0 || argument_field_check(circ, str)==0 || point_check(circ, str)==0 || comma_check(circ, str)==0 || amount_of_arguments_check(circ, str)==0) {
            return 0;
        }
        circles->x = x_reader(str);
        circles->y = y_reader(str);
        circles->R = r_reader(str);
        figur[circlescount] = circles;
        circlescount++;
    }
    for (int i = 0; i < circlescount; i++) {
        int s = square(figur[i]->R);
        int p = perimetr(figur[i]->R);
        printf("Figure number %d:\n", i + 1);
        printf("X coordinate:%f Y coordinate:%f Radius:%f Square:%d "
               "Perimetr:%d\n",
               figur[i]->x,
               figur[i]->y,
               figur[i]->R,
               s,
               p);
    }
    fclose(fp);
    return 0;
}
