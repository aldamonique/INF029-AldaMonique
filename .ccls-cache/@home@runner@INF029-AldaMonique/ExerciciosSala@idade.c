// Crie um programa que leia um número n de idades, e imprima todas as idades
// maior que a média delas

#include <stdio.h>

int main() {

  int a;
  int age[a];
  int media, soma;
  printf("Digite quantas idades voce deseja digitar:");
  scanf("%d", &a);

  for (int i = 0; i < a; i++) {

    printf("Digite a idade:");
    scanf("%d", &age[i]);
    soma += age[i];
  }

  media = soma/a;
  
  for (int i = 0; i < a; i++) {
    if(age[i]>media){
     printf("Maior que a media: %d", age[i]);
    }
  }
}