#include "heap_sort.h"
#include <stdio.h>
#include <stdlib.h> 

static void swap(int *a, int *b, unsigned long long int *contador_trocas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    if (contador_trocas != NULL) {
        (*contador_trocas)++;
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
    No* atual = lista->inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}
No* get_no(Lista* lista, int index) {
    if (index < 0 || index >= lista->tamanho) return NULL;

    No* atual;
    if (index < lista->tamanho / 2) {
        atual = lista->inicio;
        for (int i = 0; i < index; i++) atual = atual->proximo;
    } else {
        atual = lista->fim;
        for (int i = lista->tamanho - 1; i > index; i--) atual = atual->anterior;
    }
    return atual;
}

void swap_nos(No* a, No* b, unsigned long long int *contador_trocas) {
    if (a && b) {
        int temp = a->valor;
        a->valor = b->valor;
        b->valor = temp;
        if (contador_trocas) (*contador_trocas)++;
    }
}

void max_heapify_lista(Lista* lista, int n, int i, unsigned long long int *contador_trocas) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    No* no_i = get_no(lista, i);
    No* no_maior = no_i;
    No* no_esq = get_no(lista, esq);
    No* no_dir = get_no(lista, dir);

    if (esq < n && no_esq->valor > no_maior->valor) {
        maior = esq;
        no_maior = no_esq;
    }

    if (dir < n && no_dir->valor > no_maior->valor) {
        maior = dir;
        no_maior = no_dir;
    }

    if (maior != i) {
        swap_nos(no_i, no_maior, contador_trocas);
        max_heapify_lista(lista, n, maior, contador_trocas);
    }
}


void min_heapify_lista(Lista* lista, int n, int i, unsigned long long int *contador_trocas) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    No* no_i = get_no(lista, i);
    No* no_menor = no_i;
    No* no_esq = get_no(lista, esq);
    No* no_dir = get_no(lista, dir);

    if (esq < n && no_esq->valor < no_menor->valor) {
        menor = esq;
        no_menor = no_esq;
    }
    if (dir < n && no_dir->valor < no_menor->valor) {
        menor = dir;
        no_menor = no_dir;
    }
  if (menor != i) {
        swap_nos(no_i, no_menor, contador_trocas);
        min_heapify_lista(lista, n, menor, contador_trocas);
    }
  }

void heap_sort_decrescente_lista(Lista* lista, unsigned long long int *contador_trocas){
    int n = lista->tamanho;

    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify_lista(lista, n, i, contador_trocas);
    }

    for (int i = n - 1; i > 0; i--) {
        swap_nos(get_no(lista, 0), get_no(lista, i), contador_trocas);
        min_heapify_lista(lista, i, 0, contador_trocas);
    }
}

void heap_sort_crescente_lista(Lista* lista, unsigned long long int *contador_trocas){
    int n = lista->tamanho;

    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify_lista(lista, n, i, contador_trocas);
    }

    for (int i = n - 1; i > 0; i--) {
        swap_nos(get_no(lista, 0), get_no(lista, i), contador_trocas);
        max_heapify_lista(lista, i, 0, contador_trocas);
    }
}



void heap_sort_lista(Lista* lista, unsigned long long int *contador_trocas) {
    int n = lista->tamanho;

    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify_lista(lista, n, i, contador_trocas);
    }

    for (int i = n - 1; i > 0; i--) {
        swap_nos(get_no(lista, 0), get_no(lista, i), contador_trocas);
        max_heapify_lista(lista, i, 0, contador_trocas);
    }
}

void max_heapify(int arr[], int n, int i , unsigned long long int *contador_trocas) {
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
        swap(&arr[i], &arr[maior], contador_trocas);

      
        max_heapify(arr, n, maior, contador_trocas);
    }
}

void construir_max_heap(int arr[], int n , unsigned long long int *contador_trocas) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i, contador_trocas);
    }
}


void heap_sort_crescente(int arr[], int n, unsigned long long int *contador_trocas) {
    
    construir_max_heap(arr, n , contador_trocas);

    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], contador_trocas);

        
        max_heapify(arr, i, 0, contador_trocas);
    }
}


void imprimir_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void min_heapify(int arr[], int n, int i , unsigned long long int *contador_trocas) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] < arr[menor]) {
        menor = esq;
    }

    if (dir < n && arr[dir] < arr[menor]) {
        menor = dir;
    }

    if (menor != i) {
        swap(&arr[i], &arr[menor] , contador_trocas);
        min_heapify(arr, n, menor, contador_trocas);
    }
}


void construir_min_heap(int arr[], int n , unsigned long long int *contador_trocas) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i , contador_trocas);
    }
}

void heap_sort_decrescente(int arr[], int n , unsigned long long int *contador_trocas) {
    construir_min_heap(arr, n , contador_trocas);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], contador_trocas);
        min_heapify(arr, i, 0, contador_trocas);
    }
}
