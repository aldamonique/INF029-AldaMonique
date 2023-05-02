#include <stdio.h>

int main(){
  int a, b, aux;
  int *x, *y, *z;

  printf("Valor de a: ");
  scanf("%d", &a);
  printf("Digite b: ");
  scanf("%d", &b);

  a = 10;
  //criar ponteiros e inverter o valor de a com b através dos ponteiros
  x = &a;
  y = &b;
  z = &aux;

  *z = *x;
  *x = *y;
  *y = *z;

  aux = a;
  a = b;
  b = aux;

  printf("Valor de a: %d\n", a);
  printf("Valor de b: %d\n", b);

}


#include <stdio.h>

int troca(int *a, int *b){
  int aux;
  int *pAux;
  pAux = &aux;
  
  *pAux = *a;
  *a = *b;
  *b = *pAux;  

  
}
int main(){
  int a, b, aux;
  int *x, *y, *z;
  printf("Valor de a: ");
  scanf("%d", &a);
  printf("Digite b: ");
  scanf("%d", &b);
  troca(&a, &b);
  
  printf("Valor de a: %d\n", a);
  printf("Valor de b: %d\n", b);

}


/*
 a = 10;
  //criar ponteiros e inverter o valor de a com b através dos ponteiros
  x = &a;
  y = &b;
  z = &aux;

  *z = *x;
  *x = *y;
  *y = *z;

  aux = a;
  a = b;
  b = aux;

*/