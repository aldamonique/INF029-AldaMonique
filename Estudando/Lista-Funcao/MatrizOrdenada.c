#include <stdio.h>

int main(){
  int matriz[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int MatrizOrdenada(int x[3][3]);
  MatrizOrdenada(matriz);
}
int MatrizOrdenada(int x[3][3]){
    int i, j; 
    for(i=0; i<3; i++){
      for(j=0; j<3; j++){
        printf("%d ", x[i][j]);
      }
      printf("\n");
    }
}