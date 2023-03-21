#include <stdio.h>
int soma(); 


int main(){
  int n1, n2;
  printf("Digite os numeros");
  scanf("%d %d", &n1, &n2);
  int calculo;
  calculo = soma(n1, n2);
  printf("Resultado: %d \n", calculo);
}


int soma(int n1, int n2){
  
  return n1+n2;
}