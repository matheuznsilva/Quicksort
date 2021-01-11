#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

int particiona(int *V, int inicio, int final){

	int esq, dir, pivo, aux; 	// Declara��o de vari�veis locais tipo int
	
	esq = inicio;	// Esq recebe inicio do vetor
	dir = final;	// Dir recebe final do vetor
	pivo = V[inicio];	// Pivo recebe conteudo da primeira posi��o do vetor
	
	while(esq < dir){	// La�o de repeti��o tendo como ponto de parada esquerda ser maior que a direita
		while(V[esq] <= pivo){	// La�o de repeti��o tendo como ponto de parada o conteudo da posi��o esq do vetor maior que o pivor
			esq++;		// Incremento da vari�vel esq
		}
		while(V[dir] > pivo){		// La�o de repeti��o tendo como ponto de parada o conteudo da posi��o dir do vetor menor que o pivor
			dir--;		// Decremento da vari�vel dir 
		}
		if(esq < dir){		// Condicional para troca de posi��o de elementos
			aux = V[esq];		// Aux recebe V[esq]
			V[esq] = V[dir];		// V[esq] recebe V[dir]
			V[dir] = aux;		// V[esq] recebe aux;
		}
	}
	
	V[inicio] = V[dir];		// V[inicio] recebe V[dir]
	V[dir] = pivo;		// V[dir] recebe pivo
	
	return dir;		// Retorna dir
}

void quickSort(int *V, int inicio, int fim){

	//clock_t Ticks[2];
    //Ticks[0] = clock();

	int pivo;		// Declara��o de vari�vel local tipo int
	
	if(fim > inicio){
		
		pivo = particiona(V, inicio, fim);		// Chama a fun��o que divide o vetor
		quickSort(V, inicio, pivo-1);		// Chama a fun��o quickSort para continuar o particionamento de um lado do vetor
		quickSort(V, pivo+1, fim);		// Chama a fun��o quickSort para continuar o particionamento do outo lado do vetor 
	}

	//Ticks[1] = clock();
    //double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //getchar();

    //return Tempo;
}
