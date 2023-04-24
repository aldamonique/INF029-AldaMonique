#include <stdio.h>
#include <string.h>

int main(){
  char str[11];
  strcpy(str, "29/02/2015");

  char sDia[3];
  
  
  int i = 0;
  //copiar 
  for(; i < strlen(str) && str[i] != '/'; i++){
      sDia[i] = str[i];
  }
  sDia[i] = '\0';
  
  char sMes[3];
  i++;
  int j = 0;
  for(; i< strlen(str) && str[i] != '/'; i++){
    sMes[j++] = str[i];
  }
  sMes[j++] = '\0';

  char sAno[5];
  i++; 
  int k=0;
  for(; i< strlen(str) && str[i] != '/'; i++){
    sAno[k++] = str[i];
  }
  sMes[k++] = '\0';

  //imprimir
  printf("Dia: %s\n", sDia);
  printf("Mes: %s\n", sMes);
  printf("Ano: %s\n", sAno);

}