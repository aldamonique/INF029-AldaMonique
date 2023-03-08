
#include <stdio.h>
int main() {

  int a;
  float media, soma;
  printf("Digite quantas idades voce deseja processar:");
  scanf("%d", &a);
  int age[a];
  
  for (int i = 0; i < a; i++) {
    printf("Digite a idade: ");
    scanf("%d", &age[i]);
    soma += age[i];
  }
  
  media = soma/a;
  printf("%f", media);

  for (int i = 0; i < a; i++) {
    if(age[i]>media){
      printf("Maior que a media: %d", age[i]);
      printf("\n");
    }
  }
}