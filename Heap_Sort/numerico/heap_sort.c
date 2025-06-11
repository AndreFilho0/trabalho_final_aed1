#include "heap_sort.h"
#include <stdio.h>
#include <stdlib.h> 

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* heap_criar(size_t capacidade) {
    Heap *h = (Heap*) malloc(sizeof(Heap));
    if (h == NULL) {
        perror("Erro ao alocar memória para Heap");
        exit(EXIT_FAILURE);
    }
    h->array = (int*) malloc(sizeof(int) * capacidade);
    if (h->array == NULL) {
        perror("Erro ao alocar memória para o array do Heap");
        free(h);
        exit(EXIT_FAILURE);
    }
    h->tamanho_atual = 0;
    h->capacidade = capacidade;
    return h;
}

void heap_destruir(Heap *h) {
    if (h == NULL) return;
    free(h->array);
    free(h);
}

void heap_inserir(Heap *h, int valor) {
    if (h->tamanho_atual == h->capacidade) {
        fprintf(stderr, "Heap cheio, não é possível inserir.\n");
        return;
    }
    h->array[h->tamanho_atual] = valor;
    int i = h->tamanho_atual;
    h->tamanho_atual++;

        while (i != 0 && h->array[(i - 1) / 2] < h->array[i]) {
        swap(&h->array[i], &h->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int heap_extrair_max(Heap *h) {
    if (h->tamanho_atual <= 0) {
        fprintf(stderr, "Heap vazio.\n");
        return -1; 
    }
    if (h->tamanho_atual == 1) {
        h->tamanho_atual--;
        return h->array[0];
    }

    int raiz = h->array[0];
    h->array[0] = h->array[h->tamanho_atual - 1];
    h->tamanho_atual--;


    max_heapify(h->array, h->tamanho_atual, 0);

    return raiz;
}


void max_heapify(int arr[], int n, int i) {
    int maior = i;      
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2; 

    if (esq < n && arr[esq] > arr[maior]) {
        maior = esq;
    }

    
    if (dir < n && arr[dir] > arr[maior]) {
        maior = dir;
    }

    
    if (maior != i) {
        swap(&arr[i], &arr[maior]);

      
        max_heapify(arr, n, maior);
    }
}

void construir_max_heap(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}


void heap_sort(int arr[], int n) {
    
    construir_max_heap(arr, n);

    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        
        max_heapify(arr, i, 0);
    }
}


void imprimir_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
