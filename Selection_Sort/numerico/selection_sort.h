#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

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

Lista* criar_lista();
void inserir_final(Lista* lista, int valor);
void destruir_lista(Lista* lista);
void imprimir_lista(Lista* lista, int max_elementos);

void selection_sort_vetor_crescente(int arr[], int n, unsigned long long int *contador_trocas);
void selection_sort_vetor_decrescente(int arr[], int n, unsigned long long int *contador_trocas);

void selection_sort_lista_crescente(Lista* lista, unsigned long long int *contador_trocas);
void selection_sort_lista_decrescente(Lista* lista, unsigned long long int *contador_trocas);

#endif 