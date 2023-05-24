#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct Estrutura{
  int tamanho;
  int quantidade;
  int *vetorAux;
} structPrincipal;

structPrincipal vetorPrincipal[TAM];


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    if (posicao < 1 || posicao > TAM){
     return POSICAO_INVALIDA;
    }  

    if(vetorPrincipal[posicao-1].vetorAux != NULL){
      return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    //Quando se fala de ponteiros de vetires existe o ponteiro em si que aponta para o veto. E nesse caso ao verificar se é diferente de null, se constata que o ponteiro não foi alocado, é NULL
    if (tamanho <1){
      return TAMANHO_INVALIDO;
    }
  
    vetorPrincipal[posicao-1].vetorAux	=	malloc (tamanho * sizeof(int));
    //aloca dinamicamente um bloco de memória. o tamanho com o sizeof aloca um número espe-
    //cífico de de elementos inteiro na memória. guardando o espaço de memória passado no segundo parâmetro da função CriarEstruturas. alocando-a na estrutura de vetorAux. 
    vetorPrincipal[posicao-1].tamanho = tamanho;
    //é importante associar o tamanho a estrutura do vetor principal para acessos posteriores e realizações de operações relacionados ao tamanho. 
  
    if(!vetorPrincipal[posicao-1].vetorAux){
      return SEM_ESPACO_DE_MEMORIA;
    }
  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao<1 || posicao>10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao-1].vetorAux != NULL)
        {
          //testa se tem espaco
            if (vetorPrincipal[posicao-1].quantidade < vetorPrincipal[posicao-1].tamanho)
            {
              //se houver espaço, insere
              vetorPrincipal[posicao-1].vetorAux[vetorPrincipal[posicao-1].quantidade] = valor;
              vetorPrincipal[posicao-1].quantidade++;
              retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(posicao<1 || posicao>10){
      return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao-1].vetorAux == NULL){
      return SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorPrincipal[posicao-1].quantidade == 0)
      return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao-1].quantidade--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{  
    if(posicao<1 || posicao>10){
      return POSICAO_INVALIDA;
    }
   if (vetorPrincipal[posicao-1].vetorAux == NULL){
      return SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorPrincipal[posicao-1].quantidade == 0)
      return ESTRUTURA_AUXILIAR_VAZIA;

    for(int i =0; i < vetorPrincipal[posicao-1].tamanho; i++){
      if(vetorPrincipal[posicao-1].vetorAux[i] != valor)
        return NUMERO_INEXISTENTE; 

      if (vetorPrincipal[posicao - 1].vetorAux[i] == valor) {
        for (int j = i + 1; j < vetorPrincipal[posicao - 1].quantidade; j++) {
          vetorPrincipal[posicao - 1].vetorAux[j - 1] = vetorPrincipal[posicao - 1].vetorAux[j];
        }
        
      vetorPrincipal[posicao-1].quantidade--; 
      return SUCESSO;
      }
    } 
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{  
    int retorno =0;
  
    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao-1].vetorAux == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else {
        if (vetorPrincipal[posicao-1].quantidade > 0) {
            for (int i = 0; i < vetorPrincipal[posicao-1].quantidade; i++) {
                vetorAux[i] = vetorPrincipal[posicao-1].vetorAux[i];
            }
        }
        return SUCESSO;
    }
    return retorno;
}



/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
      if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
      }
      if (vetorPrincipal[posicao-1].vetorAux == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
      }

      else {
        if (vetorPrincipal[posicao-1].quantidade > 0) {
          for (int i = 0; i < vetorPrincipal[posicao-1].quantidade; i++) {
            vetorAux[i] = vetorPrincipal[posicao-1].vetorAux[i];
          }
          for(int i = 1; i < vetorPrincipal[posicao-1].quantidade; i++){ 
            for(int j = 0; j < vetorPrincipal[posicao-1].quantidade -1; j++){
              if(vetorAux[j] > vetorAux [j+1]){
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp; 
              }
            }
          }
        }
      return SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int tudoVazio=0;
    int vetorDados;
    int i, j; 
  
    for(i=0; i<TAM; i++){
      if (vetorPrincipal[i].quantidade == 0) {
        tudoVazio++;
      }
    
      if (vetorPrincipal[i].vetorAux != NULL){
        for (j = 0; j < vetorPrincipal[i].tamanho; j++) {
            vetorAux[vetorDados] = vetorPrincipal[i].vetorAux[j];
            vetorDados++;
        }
      }
    } 
   if (tudoVazio == TAM){
      return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    if(vetorDados>0){
      return SUCESSO;
    }

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int posicao, i, j; 
    int indice = 0; 
    for(posicao = 0; posicao < TAM; posicao++){
      if(vetorPrincipal[posicao].quantidade == 0){
        continue;
      }
      for(i=0; i < vetorPrincipal[posicao].quantidade; i++){
        vetorAux[indice] = vetorPrincipal[posicao].vetorAux[i];
        indice++; 
      }
    }
    for(i = 1; i < indice; i++){ 
      for(j = 0; j < indice -1; j++){
        if(vetorAux[j] > vetorAux[j+1]){
          int temp = vetorAux[j];
          vetorAux[j] = vetorAux[j+1];
          vetorAux[j+1] = temp; 
        }
      }
    }
    if(indice == 0){
      return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{
      return SUCESSO; 
    }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao - 1].vetorAux == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
   if (novoTamanho + vetorPrincipal[posicao - 1].tamanho < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }

    int tamanhoAtual = vetorPrincipal[posicao - 1].tamanho;
    int novoTamanhoTotal = tamanhoAtual + novoTamanho;

    int* novoVetorAux = realloc(vetorPrincipal[posicao - 1].vetorAux, novoTamanhoTotal * sizeof(int));
    if (novoVetorAux == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao - 1].vetorAux = novoVetorAux;
    vetorPrincipal[posicao - 1].tamanho = novoTamanhoTotal;

    return SUCESSO;
}
/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
  
*/

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao - 1].vetorAux == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorPrincipal[posicao - 1].quantidade == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
   if(vetorPrincipal[posicao-1].vetorAux!= NULL){
        if(vetorPrincipal[posicao-1].tamanho < vetorPrincipal[posicao-1].quantidade) {
        vetorPrincipal[posicao-1].quantidade = vetorPrincipal[posicao-1].tamanho;
    }}
    return vetorPrincipal[posicao - 1].quantidade;
}



/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No));
	if(novo == NULL){
        exit(1);
	}
	novo->conteudo = valor;
	novo->prox = NULL;
	return novo;
}

void inserirFinalComCabecote(No *inicio, int val){

	No* tmp;
	No* novo = criarElemento(val);

	if(inicio->prox == NULL){
		inicio->prox = novo;
	}
	else{
		tmp = inicio->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}


No* montarListaEncadeadaComCabecote()
{
	int i, j;
	int contador = 0;
	No* cabecote = (No*)malloc(sizeof(No));

	for (i = 0; i < TAM; i++){
		if (vetorPrincipal[i].vetorAux != NULL){
			if (vetorPrincipal[i].quantidade > 0){
				contador++;
				for (j = 0; j < vetorPrincipal[i].quantidade; j++){
					inserirFinalComCabecote(cabecote, vetorPrincipal[i].vetorAux[j]);
				}
			}
		}
	}

	if (contador > 0)
		return cabecote;
	else
		return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No *p;
  int index = 0;
  for (p = inicio->prox; p != NULL; p = p->prox)
    vetorAux[index++] = p->conteudo;
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;

    while (atual != NULL) {
        No *temporario = atual;
        atual = atual->prox;
        free(temporario);
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i=0; i< TAM;i++){
    vetorPrincipal[i].vetorAux = NULL;
    vetorPrincipal[i].tamanho = 0;
    vetorPrincipal[i].quantidade = 0;
  }
  //colocar todos os vetores em NULL
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for(int i=0; i< TAM; i++){
    free(vetorPrincipal[i].vetorAux);
  }
  
}