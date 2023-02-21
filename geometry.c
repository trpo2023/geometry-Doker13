#include <stdio.h>
#include <string.h>

int main() {
  char *file = "geom.txt";
  char standart[7]="circle";
  char str[100];
  FILE *fp = fopen(file, "r");
  while (!feof(fp)) {
    char si1[2];
    char si2[2];
    char ik[2];
    double x;
    double y;
    double r;
    fscanf(fp, "%s %c%lg %lg%c %lg%c", str, si1, &x, &y, ik, &r, si2);
    char pref[200];
    sprintf(pref,"%s %s%g %g%s %g%s", str, si1, x, y, ik, r, si2);
    int n = strcmp(standart, str);
    if (n!=0){
      printf("%s %s%g %g%s %g%s\n^\nError at column 0: expected 'circle'\n",str, si1, x, y, ik, r, si2);
      break;
    }
    
    int ret = 1;
    for (int j = 8; pref[j] != ')'; j++){
      if ((pref[j] >= 48 && pref[j] <= 57) || pref[j] == '.' || pref[j] == ',' || pref[j] == ' ')
        ret = 0;
        else{
          printf("Error: expected double\n");
          ret = 1;
          break;
        }
    }
    
    if (ret==1){
    break;
    }
    
    if (si1[0]!=40){
      int i=0;
      printf("%s\n", pref);
      while(si1[0]!=pref[i]){
        i++;
        printf(" ");
      }
      i++;
      printf("^\nError at column %d: expected '('\n", i);
      break;
    }
    if (ik[0]!=44){
      int i=0;
      printf("%s\n", pref);
      while(ik[0]!=pref[i]){
        i++;
        printf(" ");
      }
      i++;
      printf("^\nError at column %d: expected ','\n", i);
      break;
    }
    if (si2[0]!=41){
      printf("%s\n", pref);
      int i=strlen(pref);
      int count =i;
      while(count!=1){
        count--;
        printf(" ");
      }
      printf("^\nError at column %d: expected ')'\n", i-1);
      break;
    }
    printf("All done\n");
  }
  fclose(fp);
  return 0;
}
