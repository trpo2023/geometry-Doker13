#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char *file = "geom.txt";
  char standart[]="circle";
  FILE *fp = fopen(file, "r");
  char str[100];
  char circ[20];
  while (fscanf(fp, "%s ", circ)==1) {
    fgets(str, 100, fp);
    
    char data[20];
    int i=0;
    while(circ[i]!='\0'){
      data[i]=tolower(circ[i]);
      i++;
    }
    int n = strcmp(standart, data);
    if (n!=0){
      printf("%s %sError at column 0: expected 'circle'\n", circ, str);
      break;
    }
    
    if (str[0]!='('){
      printf("%s %sError at column 8: expected '('\n", circ, str);
      break;
    }
    
    int k=1;
    while (1){
      if (str[k+2]=='\0' && str[k]==')'){
        break;
      }
      else if (str[k]=='\0') {
        k+=6;
        printf("%s %sError at column %d: out of range\n", circ, str, k);
        break;
      }
      else{
        k++;
      }
    }
    
    int ind=1;
    for (int i = 1; str[i] != ')'; i++) {
      if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ',' || str[i] == ' ')
          ind++;
      else {
          ind+=8;
          printf("%s %sError at column %d: error in the argument field\n", circ, str, ind);
          break;
      }
    }
    
  }
  fclose(fp);
  return 0;
}
