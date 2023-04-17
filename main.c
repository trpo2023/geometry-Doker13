#include "parser.h"
#include "PaS.h"
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
    char str[100];
    char circ[20];
    int chek_m;
    while (fscanf(fp, "%s ", circ) == 1) {
        fgets(str, 100, fp);
        chek_m = Errors_checker(circ, str);
        if (chek_m == 0) {
            break;
        }
        reader(str);
    }
    if (chek_m == 1) {
        printf("All done right\n");
    }
    fclose(fp);
    return 0;
}
