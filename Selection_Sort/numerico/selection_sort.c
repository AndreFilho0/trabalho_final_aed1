#include "selection_sort.h"
#include <stdio.h>
#include <stdlib.h>

static void swap_int(int *a, int *b, unsigned long long int *contador_trocas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    if (contador_trocas) {
        (*contador_trocas)++;
    }
}

static void swap_nos(No* a, No* b, unsigned long long int *contador_trocas) {
    if (a && b) {
        int temp = a->valor;
        a->valor = b->valor;
        b->valor = temp;
        if (contador_trocas) {
            (*contador_trocas)++;
        }
    }
}

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserir_final(Lista* lista, int valor) {
    No* novo = malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    if (lista->fim)
        lista->fim->proximo = novo;
    else
        lista->inicio = novo;
    lista->fim = novo;
    lista->tamanho++;
}

void destruir_lista(Lista* lista) {
    if (!lista) return;
    No* atual = lista->inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}

void imprimir_lista(Lista* lista, int max_elementos) {
    if (!lista) return;
    No *atual = lista->inicio;
    for (int i = 0; i < max_elementos && atual != NULL; i++) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}



void selection_sort_vetor_crescente(int arr[], int n, unsigned long long int *contador_trocas) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap_int(&arr[min_idx], &arr[i], contador_trocas);
        }
    }
}

void selection_sort_vetor_decrescente(int arr[], int n, unsigned long long int *contador_trocas) {
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap_int(&arr[max_idx], &arr[i], contador_trocas);
        }
    }
}


void selection_sort_lista_crescente(Lista* lista, unsigned long long int *contador_trocas) {
    if (!lista || lista->tamanho < 2) return;

    No *i, *j;
    for (i = lista->inicio; i->proximo != NULL; i = i->proximo) {
        No *min_no = i;
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (j->valor < min_no->valor) {
                min_no = j;
            }
        }
        if (min_no != i) {
            swap_nos(i, min_no, contador_trocas);
        }
    }
}

void selection_sort_lista_decrescente(Lista* lista, unsigned long long int *contador_trocas) {
    if (!lista || lista->tamanho < 2) return;

    No *i, *j;
    for (i = lista->inicio; i->proximo != NULL; i = i->proximo) {
        No *max_no = i;
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (j->valor > max_no->valor) {
                max_no = j;
            }
        }
        if (max_no != i) {
            swap_nos(i, max_no, contador_trocas);
        }
    }
}