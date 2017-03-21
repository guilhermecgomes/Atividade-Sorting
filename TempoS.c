/*
  Arquivo: SORTING_GabrielBellaMartini.c
  Autor: GABRIEL BELLA MARTINI e GUILHERME DO CARMO GOMES
  Date 20/03/17 07:32
  Descrição: Este programa determina o tempo de execução de alguns 
  dos algoritmos de ordenação.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Biblioteca.h"

main( ){
    ListaInt listaA,listaB,listaC,listaD;
    double d;
    struct tm *ptr;       // struct tm guarda os dados do calendário
    time_t inicio;        // o tipo time_t está definido em time.h
    inicio = time(NULL);  //tempo corrente em uma variável do tipo time_t
    printf("\n\n  Data e hora corrente:  ");
    ptr = localtime(&inicio);  printf(asctime(ptr));      // exibir a data e hora na tela
    clock_t start, finish;
    double pf;
    printf("\n  Construir uma lista com inteiros positivos menores que 100000 \n\n ");
    printf(" Tamanho da lista = %d itens", Max-1);
    printf(" \n");
    construirLista(&listaA,Max-1);  mostrarLista(&listaA);
    copiarLista(&listaA,&listaB);
    copiarLista(&listaA,&listaC);
    copiarLista(&listaA,&listaD);
     
	/////////////////// BUBBLESORT///////////////////////////////////////////////////////////
    start = clock();
    printf("\n\n");    mostrarLista(&listaA);
    ordenarListaCrescenteB(&listaA);  
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("          elapsed = %e nanosegundos ",pf);
    /////////////////////////////////////////////////////////////////////////////////////// 
   
    /////////////////// SELECTIONSORT///////////////////////////////////////////////////////////
    start = clock();
    printf("\n\n");    mostrarLista(&listaB);
    ordenarListaCrescenteS(&listaB);  
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("       elapsed = %e nanosegundos ",pf);
    ///////////////////////////////////////////////////////////////////////////////////////
     
    /////////////////// INSERTIONSORT///////////////////////////////////////////////////////////
    start = clock();
    printf("\n\n");    mostrarLista(&listaC);
    ordenarListaCrescenteI(&listaC);  
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("      elapsed = %e nanosegundos ",pf);
    ///////////////////////////////////////////////////////////////////////////////////////
     
    /////////////////// QUICKSORT///////////////////////////////////////////////////////////
    start = clock(); // clock devolve o tempo de CPU desde o início da execução do programa.
    printf(" \n\n\n");      printf("		QuickSort "); quicksort(&listaD,1,Max-1); 
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("           elapsed = %e nanosegundos ",pf); printf(" \n"); 
    ///////////////////////////////////////////////////////////////////////////////////////
     
    printf("\nOrdenacao com a Lista Crescente\n");
    
    /////////////////// BUBBLESORT///////////////////////////////////////////////////////////
    start = clock();
    printf("\n\n");    mostrarLista(&listaA);
    ordenarListaCrescenteB(&listaA);  
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("          elapsed = %e nanosegundos ",pf);
    /////////////////////////////////////////////////////////////////////////////////////// 
   
    /////////////////// SELECTIONSORT///////////////////////////////////////////////////////////
    start = clock();
    printf("\n\n");    mostrarLista(&listaB);
    ordenarListaCrescenteS(&listaB);  
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("       elapsed = %e nanosegundos ",pf);
    ///////////////////////////////////////////////////////////////////////////////////////
     
    /////////////////// INSERTIONSORT///////////////////////////////////////////////////////////
    start = clock();
    printf("\n\n");    mostrarLista(&listaC);
    ordenarListaCrescenteI(&listaC);  
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("      elapsed = %e nanosegundos ",pf);
    ///////////////////////////////////////////////////////////////////////////////////////
     
    /////////////////// QUICKSORT///////////////////////////////////////////////////////////
    start = clock(); // clock devolve o tempo de CPU desde o início da execução do programa.
    printf(" \n\n\n");      printf("		QuickSort "); quicksort(&listaD,1,Max-1); 
    finish = clock();
    pf = (double)(finish - start)*1000000*1000/CLOCKS_PER_SEC;
    printf("           elapsed = %e nanosegundos ",pf); printf(" \n"); 
    ///////////////////////////////////////////////////////////////////////////////////////
    
    printf("\nOrdenacao com a Lista Decrescente\n");
    
    ordenarListaDecrescenteB(&listaA);
    mostrarLista(&listaA);
    
    printf("\n\n");
    system("PAUSE");
}


