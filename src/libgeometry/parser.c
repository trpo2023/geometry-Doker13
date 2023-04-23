#include <ctype.h>
#include <libgeometry/parser.h>
#include <stdio.h>
#include <string.h>

#define zeroASCII 48
#define nineASCII 57

int word_check(char* circ, char* str)
{
    char standart[] = "circle";
    char data[20];
    int i = 0;
    while (circ[i] != '\0') {
        data[i] = tolower(circ[i]);
        i++;
    }
    int n = strcmp(standart, data);
    if (n != 0) {
        printf("%s %sError at column 0: expected 'circle'\n", circ, str);
        return 0;
    }
    return 1;
}

int first_bkt_check(char* circ, char* str)
{
    if (str[0] != '(') {
        printf("%s %sError at column 8: expected '('\n", circ, str);
        return 0;
    }
    return 1;
}

int second_bkt_check(char* circ, char* str)
{
    int u = 0;
    while (1) {
        if (str[u] == ')') {
            return 1;
        } else if (str[u] == '\0') {
            u += 8;
            printf("%s %sError at column %d: expected ')'\n", circ, str, u);
            return 0;
        } else {
            u++;
        }
    }
}

int arguments_check(char* circ, char* str)
{
    int a = -1;
    int cnt = 0;
    while (str[a] != ')') {
        a++;
        if (str[a] > 47 && str[a] < 58) {
            cnt++;
            break;
        }
    }
    if (cnt == 0) {
        printf("%s %sError at column 9: expected arguments\n", circ, str);
        return 0;
    }
    return 1;
}

int range_check(char* circ, char* str)
{
    int k = 1;
    while (1) {
        if (str[k + 2] == '\0' && str[k] == ')') {
            return 1;
        } else if (str[k] == '\0') {
            k += 6;
            printf("%s %sError at column %d: out of range\n", circ, str, k);
            return 0;
        } else {
            k++;
        }
    }
}

int argument_field_check(char* circ, char* str)
{
    int ind = 1;
    for (int i = 1; str[i] != ')'; i++) {
        if ((str[i] >= zeroASCII && str[i] <= nineASCII) || str[i] == '.'
            || str[i] == ',' || str[i] == ' ')
            ind++;
        else {
            ind += 8;
            printf("%s %sError at column %d: error in the argument field\n",
                   circ,
                   str,
                   ind);
            return 0;
        }
    }
    return 1;
}

int point_check(char* circ, char* str)
{
    int y = 1;
    int countp = 0;
    while (str[y] != ')') {
        if (str[y] == '.') {
            countp++;
            if (countp > 3) {
                y += 4;
                printf("%s %sError at column %d: extra point\n", circ, str, y);
                return 0;
            } else if (
                    (str[y - 1] < zeroASCII || str[y - 1] > nineASCII)
                    || (str[y + 1] < zeroASCII || str[y + 1] > nineASCII)) {
                y += 3;
                printf("%s %sError at column %d: error in argument field\n",
                       circ,
                       str,
                       y);
                return 0;
            }
            y++;
        } else {
            y++;
        }
    }
    return 1;
}

int comma_check(char* circ, char* str)
{
    int g = 1;
    int countc = 0;
    while (str[g] != ')') {
        if (str[g] == ',') {
            countc++;
            g++;
            if (countc > 1) {
                g += 7;
                printf("%s %sError at column %d: extra comma\n", circ, str, g);
                return 0;
            }
        } else {
            g++;
        }
    }
    if (countc == 0) {
        printf("%s %sError: expected comma in arrgument field\n", circ, str);
        return 0;
    }
    return 1;
}

int amount_of_arguments_check(char* circ, char* str)
{
    int h = 0;
    int countnum = 0;
    int end = 0;
    while (str[h - 1] != ')') {
        if ((str[h] > zeroASCII - 1 && str[h] < nineASCII + 1)
            || str[h] == '.') {
            int countp2 = 0;
            while (1) {
                if (str[h] == '.') {
                    countp2++;
                    if (countp2 > 1) {
                        h += 8;
                        printf("%s %sError at column %d: more then one point "
                               "in argument\n",
                               circ,
                               str,
                               h);
                        return 0;
                    }
                }
                if (str[h] == ' ') {
                    countnum++;
                    h++;
                    break;
                } else if (str[h] == ',') {
                    if (countnum == 1) {
                        countnum++;
                        h++;
                        break;
                    } else if (countnum > 1) {
                        h += 7;
                        printf("%s %sError at column %d: extra argument\n",
                               circ,
                               str,
                               h);
                        return 0;
                    } else {
                        h += 9;
                        printf("%s %sError at column %d: expected one more "
                               "argument\n",
                               circ,
                               str,
                               h);
                        return 0;
                    }
                } else if (str[h] == ')') {
                    if (countnum == 2) {
                        countnum++;
                        h++;
                        end = 1;
                        break;
                    } else if (countnum > 2) {
                        h += 8;
                        printf("%s %sError at column %d: extra argument\n",
                               circ,
                               str,
                               h);
                        return 0;
                    } else {
                        h += 2;
                        printf("%s %sError at column %d: expected one more "
                               "argument\n",
                               circ,
                               str,
                               h);
                        return 0;
                    }
                }
                h++;
            }
        } else {
            h++;
        }
        if (end == 1) {
            break;
        }
    }
    if (countnum == 2 || countnum == 1) {
        h += 6;
        printf("%s %sError at column %d: expected one more argument\n",
               circ,
               str,
               h);
        return 0;
    }
    return 1;
}
