#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h> 

typedef struct No {
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void heap_sort_crescente(int arr[], int n , unsigned long long int *contador_trocas);

void imprimir_array(int arr[], int n);

void heap_sort_decrescente_lista(Lista* lista, unsigned long long int *contador_trocas);
void heap_sort_crescente_lista(Lista* lista, unsigned long long int *contador_trocas);

Lista* criar_lista();
void inserir_final(Lista* lista, int valor);
void destruir_lista(Lista* lista);

void heap_sort_decrescente(int arr[], int n , unsigned long long int *contador_trocas);

#endif 
