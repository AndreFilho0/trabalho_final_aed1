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
