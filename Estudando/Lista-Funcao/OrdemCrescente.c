#include <stdio.h>

int main(){
  int vetor[5] = {56, 23, 1, 9, 0};
  int ordemCrescente(int vetor[], int length);
  ordemCrescente(vetor, 5);
  for(int i=0; i < 5; i++){
    printf("%d \n", vetor[i]);
  }
}
int ordemCrescente(int vetor[], int length){

  int i, j, Temp;

  for (i=0; i< length; i++){
    for(j= i+1; j<length; j++){
      if(vetor[i] > vetor[j]){
        Temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = Temp;
      }
    }
  }
}