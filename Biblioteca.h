/*
  Arquivo: Biblioteca.h
  Autor: GABRIEL BELLA MARTINI e GUILHERME DO CARMO GOMES
  Date 20/03/17 07:32
  Descrição: Este programa determina o tempo de execução de alguns 
  dos algoritmos de ordenação.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define Max 41

typedef struct {
      int tamanho;
      int vetor[Max];
} ListaInt;

void construirLista(ListaInt *,int);
void criarLista(ListaInt *);
void copiarLista(ListaInt *, ListaInt *);
void ordenarListaCrescenteS(ListaInt *);
void ordenarListaCrescenteB(ListaInt *);
void ordenarListaCrescenteI(ListaInt *);
void quicksort(ListaInt *, int, int);
void mostrarLista(ListaInt *);


void construirLista(ListaInt *ap, int n){
       int i,k,g,a,b;
       if (n > Max-1) n=Max-1;
       ap->tamanho = n;
       a = 1;
       b = 100000;
       double d;
       srand((int) time(NULL));
       for(i=1; i < n+1; i++){
                d = (double)rand()/((double)RAND_MAX +1);
                k = (int)(d*(b-a));
                g = a+k;
                ap->vetor[i] = g;
                };
     }

void copiarLista(ListaInt *ap, ListaInt *bp){
     int i,j,n;
     n=ap->tamanho;
     bp->tamanho = n;
     if (n != 0){
          for(i=1;i<=n;i++) bp->vetor[i]=ap->vetor[i];
     }
}

void criarLista(ListaInt *ap){
     ap->tamanho = 0;
}

void mostrarLista(ListaInt *ap){
     int n,i;
     n = ap->tamanho;
     printf("tamanho da lista = %d \n",n);  
     for(i=1;i<n+1;i++){ printf(" %d ",ap->vetor[i]);}
     printf("\n");
}

int separa_pf (ListaInt *ap, int l, int r){
    int pivo = ap->vetor[l];
    int i = l+1;
    int j = r;  
    int item;           
    while (i <= j) {
          if (ap->vetor[i] <= pivo) i=i+1;                           
          else if (pivo < ap->vetor[j]) j=j-1;                       
          else {
               item = ap->vetor[i];	 ap->vetor[i] = ap->vetor[j];	 ap->vetor[j] = item;                                        
	           i=i+1; j=j-1;
          } // fim else                                             
    } // fim while
    ap->vetor[l] = ap->vetor[j];
    ap->vetor[j] = pivo;
    return j;                                   
}   

void quicksort(ListaInt *ap, int p, int r){
     int j;
     if (p < r) {
           j = separa_pf (ap, p, r); 
           quicksort(ap, p, j-1); 
           quicksort(ap, j+1, r);               
     }  // fim if
}

void ordenarListaCrescenteS(ListaInt *ap){    /* idéia: localizar o menor e colocar no seu lugar */
     int i,j,min,n,aux;
     printf(" \n\n\n");     printf("		SelectionSort ");
     n = ap->tamanho;               /* n = quantidade de elementos da lista */
     for(i=1;i<n;i++){                 
         min = i;                   /* min = local onde se encontra o menor */
         for(j=i+1;j<n+1; j++) if (ap->vetor[j] < ap->vetor[min]) min = j;  /* atualização de min */
         aux = ap->vetor[i]; ap->vetor[i] = ap->vetor[min]; ap->vetor[min] = aux;  /* troca com o menor */
     } // fim for i
}

void ordenarListaCrescenteB(ListaInt *ap){    /* bolha: trocar pares consecutivos fora da ordem */
     int i,j,fim,n,aux;
     printf(" \n\n\n");     printf("		BubbleSort ");
     n = ap->tamanho; /* n = quantidade de elementos da lista */
     fim = n-1;               
     for(i=1;i<n;i++)   /* n-1 etapas  */
         for(j=1;j<fim+1; j++){      /* comparar/trocar do primeiro ao penultimo */
            if (ap->vetor[j] > ap->vetor[j+1]){
                aux = ap->vetor[j]; ap->vetor[j] = ap->vetor[j+1]; ap->vetor[j+1] = aux;
            }; // fim if
            fim = fim--;
         } // fim for j
}

void ordenarListaCrescenteI(ListaInt *ap){    /* ordenação por inserção */
     int i,k,n,aux;
     printf(" \n\n\n");     printf("		Insertion Sort ");
     n = ap->tamanho; /* n = quantidade de elementos da lista */
     for(i=2;i<n+1;i++){   
         aux = ap->vetor[i];
         k = i-1;
         while ((k>0) && (ap->vetor[k] > aux)) {ap->vetor[k+1] = ap->vetor[k]; k = k - 1;}
         ap->vetor[k+1] = aux;
     } // fim for i
}

void ordenarListaDecrescenteB(ListaInt *ap){    /* bolha: trocar pares consecutivos fora da ordem */
     int i,j,fim,n,aux;
     printf(" \n\n\n");     printf("		BubbleSort ");
     n = ap->tamanho; /* n = quantidade de elementos da lista */
     fim = n-1;               
     for(i=1;i<n;i++)   /* n-1 etapas  */
         for(j=1;j<fim+1; j++){      /* comparar/trocar do primeiro ao penultimo */
            if (ap->vetor[j] > ap->vetor[j+1]){
                aux = ap->vetor[j]; ap->vetor[j] = ap->vetor[j+1]; ap->vetor[j+1] = aux;
            }; // fim if
            fim = fim--;
         } // fim for j
}
