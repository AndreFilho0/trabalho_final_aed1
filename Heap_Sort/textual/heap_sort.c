#include"heap_sort.h"
#include <stdio.h>
#include <string.h>


static void swap(char** a, char** b, unsigned long long int* contador_trocas) {
    char* temp = *a;
    *a = *b;
    *b = temp;
    if (contador_trocas != NULL) {
        (*contador_trocas)++;
    }
}

void max_heapify(char* arr[], int n, int i, unsigned long long int* contador_trocas) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && strcmp(arr[esq], arr[maior]) > 0) {
        maior = esq;
    }

    if (dir < n && strcmp(arr[dir], arr[maior]) > 0) {
        maior = dir;
    }

    if (maior != i) {
        swap(&arr[i], &arr[maior], contador_trocas);
        max_heapify(arr, n, maior, contador_trocas);
    }
}

void imprimir_array(char* arr[], int n){
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void construir_max_heap(char* arr[], int n, unsigned long long int* contador_trocas) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i, contador_trocas);
    }
}

void heap_sort_crescente(char* arr[], int n, unsigned long long int* contador_trocas) {
    construir_max_heap(arr, n, contador_trocas);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], contador_trocas);
        max_heapify(arr, i, 0, contador_trocas);
    }
}


void min_heapify(char* arr[], int n, int i, unsigned long long int* contador_trocas) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && strcmp(arr[esq], arr[menor]) < 0) {
        menor = esq;
    }

    if (dir < n && strcmp(arr[dir], arr[menor]) < 0) {
        menor = dir;
    }

    if (menor != i) {
        swap(&arr[i], &arr[menor], contador_trocas);
        min_heapify(arr, n, menor, contador_trocas);
    }
}


void construir_min_heap(char* arr[], int n, unsigned long long int* contador_trocas) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i, contador_trocas);
    }
}


void heap_sort_decrescente(char* arr[], int n, unsigned long long int* contador_trocas) {
    construir_min_heap(arr, n, contador_trocas);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], contador_trocas);
        min_heapify(arr, i, 0, contador_trocas);
    }
}



