#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h> 


void heap_sort_crescente(char* arr[], int n, unsigned long long int* contador_trocas);
void heap_sort_decrescente(char* arr[], int n, unsigned long long int* contador_trocas);
void imprimir_array(char* arr[], int n);

#endif 
