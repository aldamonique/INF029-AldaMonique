// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Alda Monique Gonçalves de Alcantara Santos
//  email: aldamonique.goncalves@gmail.com
//  Matrícula: 20222160009
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "AldaMonique20222160009.h" 
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>


/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}


DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
    if (data[i] >= 48 && data[i] <=57)
		  sDia[i] = data[i];	
    else{
      dq.valido = 0;
      return dq;
    }
	}
  
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  
    dq.iDia = atoi(sDia);
	}else {
		dq.valido = 0;
    return dq;
  }  
	
	int j = i + 1; 
	i = 0;

	for (; data[j] != '/'; j++){
    if(data[j] >= 48 && data[j] <=58 ){
		  sMes[i] = data[j];
		  i++;
    }else {
      dq.valido = 0;
      return dq; 
    }
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  
    dq.iMes = atoi(sMes);
	}else {
		dq.valido = 0;
    return dq;
  }
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
     if(data[j] >= 48 && data[j] <=58 ){
       sAno[i] = data[j];
	 	   i++;
     }else {
      dq.valido = 0;
      return dq; 
    }
	} 
  
	if( i == 1||i == 2 || i == 4){ // testa se tem 1, 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
      if (i==1 || i == 2){
        dq.iAno = atoi(sAno) + 2000; 
      }
      if(i==4){
        dq.iAno = atoi(sAno);
      }
	}else {
		dq.valido = 0;
    return dq;
  }
  
  dq.iMes = atoi(sMes);
	dq.valido = 1;
    
  return dq;
}  

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
    Sempre que tiver dois dígitos no ano soma-se com 2000
 */

int q1(char data[]) {
  int datavalida = 1;
	printf("%s\n", data);
  DataQuebrada dataQuebrada = quebraData(data); 
  if (dataQuebrada.valido == 0){
		return 0;
	}
 return validarData(dataQuebrada); 
}

int validarData (DataQuebrada datasSeparadas) {

  if (datasSeparadas.iDia < 0 || datasSeparadas.iMes < 0 || datasSeparadas.iMes > 12 || datasSeparadas.iAno < 0) {
    return 0;
  }
    
  int diaAux;
  switch (datasSeparadas.iMes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      diaAux = 31; 
    case 4: case 6: case 9: case 11:
      diaAux = 30;
    case 2:
      if (((datasSeparadas.iAno % 4 == 0) && (datasSeparadas.iAno % 100 != 0)) || datasSeparadas.iAno % 400 == 0){
        diaAux = 29;
      } else {
        diaAux = 28;
      }
    default:
      return 0;
  }

  if (datasSeparadas.iDia > diaAux) {
    return 0;
  } 

  return 1; 
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */


DiasMesesAnos q2(char datainicial[], char datafinal[])
{

  DiasMesesAnos dma;

  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  } 

  DataQuebrada dmaInicial = quebraData(datainicial);
  DataQuebrada dmaFinal = quebraData(datafinal);
  if(dmaInicial.iAno > dmaFinal.iAno){
    dma.retorno = 4;
    return dma;
  }
  else if(dmaInicial.iAno == dmaFinal.iAno && dmaInicial.iMes > dmaFinal.iMes){
    dma.retorno = 4;
    return dma;
  } else if(dmaInicial.iAno == dmaFinal.iAno && dmaInicial.iMes == dmaFinal.iMes && dmaInicial.iDia > dmaFinal.iDia){
    dma.retorno = 4;
    return dma;
  }
  int qtdAnos = dmaFinal.iAno - dmaInicial.iAno;
  int qtdMeses = dmaFinal.iMes - dmaInicial.iMes;
  int qtdDias = dmaFinal.iDia - dmaInicial.iDia;

  if(qtdDias <0){
  switch (dmaFinal.iMes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      qtdDias += 31; 
    break;
    case 4: case 6: case 9: case 11:
      qtdDias += 30;
    break;
    case 2:{
      if (((dmaFinal.iAno % 4 == 0) && (dmaFinal.iAno % 100 != 0)) || dmaFinal.iAno % 400 == 0){
        qtdDias += 29;
      } else {
        qtdDias += 28;
      }
    }
  }
  qtdMeses--;
  if (qtdMeses < 0) {
     qtdMeses += 12;
     qtdAnos--;
  }
}
  dma.qtdDias = qtdDias;
  dma.qtdMeses = qtdMeses;
  dma.qtdAnos = qtdAnos;
  dma.retorno = 1;
  return dma;

}
  

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = 0;

  if (isCaseSensitive == 1) {
    for (int i = 0; texto[i] != '\0'; i++) {
      if (texto[i] == c) {
        qtdOcorrencias++;
      }
    }
  } else {
    if (c >= 'A' && c <= 'Z') {
      c += 32;
    } else if (c >= 'a' && c <= 'z') {
      c -= 32;
    }

    for (int i = 0; texto[i] != '\0'; i++) {
      if (texto[i] == c) {
        qtdOcorrencias++;
      } else if (texto[i] >= 'A' && texto[i] <= 'Z') {
        if (texto[i] + 32 == c) { 
          qtdOcorrencias++;
        }
      } else if (texto[i] >= 'a' && texto[i] <= 'z') {
        if (texto[i] - 32 == c) { 
          qtdOcorrencias++;
        }
      }
    }
  }
  return qtdOcorrencias;
}
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */

int q4(char *texto, char *palavra_busca, int posicoes[30]) {
    return contar_palavras(texto, palavra_busca, posicoes);
}

int contar_palavras(char *texto, char *palavra_busca, int posicoes[30]) {
    int tamanho_busca, tamanho_texto;  
    tamanho_texto = strlen(texto);
    tamanho_busca = strlen(palavra_busca);
    int posicao_atual = 0;
    int contagem_ocorrencias = 0;
    int i, j = 0;
    int letras_verificadas = 0;

    for (i = 0; texto[i] != '\0'; i++) {
        if (palavra_busca[j] == texto[i])
            j++;
        else
            j = 0;
        if (j == tamanho_busca) {
            j = 0;
            posicoes[posicao_atual] = i + 1 - (tamanho_busca - 1);
            posicao_atual++;
            posicoes[posicao_atual] = i + 1;
            posicao_atual++;
            contagem_ocorrencias++;
        }
    }
    return contagem_ocorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */


int q5(int num) {
  int inversor = 0;
  while (num != 0) {
    inversor = (inversor * 10) + (num % 10);
    num = num / 10;
  }
  return inversor;
}
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */


int q6(int numeroBase, int numBusca){
    
  int qtdOcorrencias = 0; 
  int restoNum, restoNumBusca;
  int contador;
  int numBuscaCop = numBusca; 

 
  if(numeroBase == 0 && numBusca == 0){
    qtdOcorrencias++; 
  }
  if (numBusca > 10){


    while(numeroBase > 0){
      restoNum = numeroBase % 10;
      restoNumBusca = numBusca % 10;
  
      if(restoNum == restoNumBusca){
        contador = 1;
        while(restoNum == restoNumBusca && numeroBase > 0 && contador > 0){
          numeroBase = numeroBase / 10;
          numBusca = numBusca / 10;
          restoNum = numeroBase % 10;
          restoNumBusca = numBusca % 10;
    
          if(numBusca < 10 && numBusca == restoNum){
            restoNum = numeroBase;
            contador = -1;
          }
          if(contador < 0){
            qtdOcorrencias++;
            numeroBase = numeroBase / 10;
            numBusca = numBuscaCop;
          }
        }
      }else{
        numeroBase = numeroBase / 10;
        numBusca = numBuscaCop;
      }
    }
  }
  else{
    for (; numeroBase > 0; ){
      restoNum = numeroBase % 10;
      if (restoNum == numBusca) 
      {
        qtdOcorrencias++;
      }
      numeroBase = numeroBase / 10;
    }
  } 
  return qtdOcorrencias; 
}
