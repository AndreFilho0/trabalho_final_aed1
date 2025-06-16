#ifndef SELECTION_SORT_TEXTUAL_H
#define SELECTION_SORT_TEXTUAL_H

#include <stddef.h>

typedef struct NoTextual {
    char *valor;
    struct NoTextual *anterior;
    struct NoTextual *proximo;
} NoTextual;

typedef struct ListaTextual {
    NoTextual *inicio;
    NoTextual *fim;
    int tamanho;
} ListaTextual;

ListaTextual* criar_lista_textual();

void inserir_final_textual(ListaTextual* lista, const char* valor);

void destruir_lista_textual(ListaTextual* lista);

void imprimir_lista_textual(ListaTextual* lista, int max_elementos);

void selection_sort_vetor_crescente_textual(char *arr[], int n, unsigned long long int *contador_trocas);

void selection_sort_vetor_decrescente_textual(char *arr[], int n, unsigned long long int *contador_trocas);

void selection_sort_lista_crescente_textual(ListaTextual* lista, unsigned long long int *contador_trocas);

void selection_sort_lista_decrescente_textual(ListaTextual* lista, unsigned long long int *contador_trocas);

#endif 