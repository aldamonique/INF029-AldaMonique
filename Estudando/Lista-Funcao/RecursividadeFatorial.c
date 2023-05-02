#include <stdio.h> 

int main(){
  int num;
  int fatorial(int x);
  printf("Digite qual numero voce quer fatorar: ");
  scanf("%d", &num);
  printf("Resultado do fatorial de %d: %d", num, fatorial(num));
}
int fatorial(int x){
  int resultado;
  if (x==0){
    resultado =1;
  }
  else{
    resultado = x * fatorial(x-1);
  }
  return resultado;
}