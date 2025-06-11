#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h> 

typedef struct {
    int *array;
    size_t tamanho_atual; 
    size_t capacidade;    
} Heap;


Heap* heap_criar(size_t capacidade);

void heap_destruir(Heap *h);

void heap_inserir(Heap *h, int valor);

int heap_extrair_max(Heap *h);

void construir_max_heap(int arr[], int n);

void max_heapify(int arr[], int n, int i);

void heap_sort(int arr[], int n);

void imprimir_array(int arr[], int n);

#endif 
