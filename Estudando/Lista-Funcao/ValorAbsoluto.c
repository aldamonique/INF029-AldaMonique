#include <stdio.h>
float inverterNumero(float num);
float soma(float num1, float num2);

int main(){
  float num1, num2;
  printf("Digite dois numeros: ");
  scanf("%f %f", &num1, &num2);
  printf("A soma absoluta dos numeros eh: %f", soma(num1, num2));
}
float soma(float num1, float num2){
  if (num1 < 0)
    num1 = inverterNumero(num1);
  if (num2< 0)
    num2 = inverterNumero(num2);
    
  return num1 + num2;  
}
float inverterNumero(float num){

  num = num * -1;
  return num;
}