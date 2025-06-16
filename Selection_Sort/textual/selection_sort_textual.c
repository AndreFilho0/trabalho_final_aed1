#include "selection_sort_textual.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap_str(char **a, char **b, unsigned long long int *contador_trocas) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    if (contador_trocas) {
        (*contador_trocas)++;
    }
}


ListaTextual* criar_lista_textual() {
    ListaTextual* lista = malloc(sizeof(ListaTextual));
    if(lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserir_final_textual(ListaTextual* lista, const char* valor) {
    NoTextual* novo = malloc(sizeof(NoTextual));
    if (!novo) return;
    novo->valor = strdup(valor); 
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    if (lista->fim)
        lista->fim->proximo = novo;
    else
        lista->inicio = novo;
    lista->fim = novo;
    lista->tamanho++;
}

void destruir_lista_textual(ListaTextual* lista) {
    if (!lista) return;
    NoTextual* atual = lista->inicio;
    while (atual) {
        NoTextual* temp = atual;
        atual = atual->proximo;
        free(temp->valor); 
        free(temp);         
    }
    free(lista);
}

void imprimir_lista_textual(ListaTextual* lista, int max_elementos) {
    if(!lista) return;
    NoTextual* atual = lista->inicio;
    for(int i=0; i < max_elementos && atual != NULL; i++) {
        printf("%s\n", atual->valor);
        atual = atual->proximo;
    }
}

void selection_sort_vetor_crescente_textual(char *arr[], int n, unsigned long long int *contador_trocas) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap_str(&arr[min_idx], &arr[i], contador_trocas);
        }
    }
}

void selection_sort_vetor_decrescente_textual(char *arr[], int n, unsigned long long int *contador_trocas) {
     int i, j, max_idx;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[max_idx]) > 0) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap_str(&arr[max_idx], &arr[i], contador_trocas);
        }
    }
}


void selection_sort_lista_crescente_textual(ListaTextual* lista, unsigned long long int *contador_trocas) {
    if (!lista || lista->tamanho < 2) return;
    NoTextual *i, *j;
    for (i = lista->inicio; i->proximo != NULL; i = i->proximo) {
        NoTextual *min_no = i;
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (strcmp(j->valor, min_no->valor) < 0) {
                min_no = j;
            }
        }
        if (min_no != i) {
            swap_str(&(i->valor), &(min_no->valor), contador_trocas);
        }
    }
}

void selection_sort_lista_decrescente_textual(ListaTextual* lista, unsigned long long int *contador_trocas) {
    if (!lista || lista->tamanho < 2) return;
    NoTextual *i, *j;
    for (i = lista->inicio; i->proximo != NULL; i = i->proximo) {
        NoTextual *max_no = i;
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (strcmp(j->valor, max_no->valor) > 0) {
                max_no = j;
            }
        }
        if (max_no != i) {
            swap_str(&(i->valor), &(max_no->valor), contador_trocas);
        }
    }
}