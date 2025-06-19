#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heap_sort.h"

#define MAX_LINHAS 1000000
#define TAM_LINHA 200

int ler_dados_texto(const char *caminho, char **dados) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int count = 0;
    char linha[TAM_LINHA];
    while (fgets(linha, sizeof(linha), arquivo) != NULL && count < MAX_LINHAS) {
        linha[strcspn(linha, "\r\n")] = '\0'; 
        dados[count] = strdup(linha); 
        count++;
    }

    fclose(arquivo);
    return count;
}

void liberar_dados_texto(char **dados, int n) {
    for (int i = 0; i < n; i++) {
        free(dados[i]);
    }
}

void copiar_dados(char **dest, char **src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = strdup(src[i]);
    }
}

void testar_heap_sort_texto(const char *descricao, char **dados_original, int n, int decrescente) {
    char **dados = malloc(n * sizeof(char *));
    if (!dados) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    copiar_dados(dados, dados_original, n);

    printf("\n\n--- %s ----\n", descricao);
    printf("Quantidade de elementos: %d\n", n);

    clock_t inicio = clock();
    unsigned long long int contador_trocas = 0;

    if (decrescente) {
        printf("Ordenando em ordem DECRESCENTE...\n");
        heap_sort_decrescente(dados, n, &contador_trocas);
    } else {
        printf("Ordenando em ordem CRESCENTE...\n");
        heap_sort_crescente(dados, n, &contador_trocas);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.7f segundos\n", tempo);
    printf("Número de trocas: %llu\n", contador_trocas);

    int exibir = n > 20 ? 20 : n;
    printf("Primeiros %d nomes:\n", exibir);
    for (int i = 0; i < exibir; i++) {
        printf("%s\n", dados[i]);
    }

    liberar_dados_texto(dados, n);
    free(dados);
}

int main() {
    const char *caminho_arquivo = "dados_de_entrada/textuais/nomes_aleatorios.txt";

    char **dados_original = malloc(MAX_LINHAS * sizeof(char *));
    if (!dados_original) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    int n = ler_dados_texto(caminho_arquivo, dados_original);
    if (n <= 0) {
        fprintf(stderr, "Erro ao ler o arquivo ou arquivo vazio.\n");
        free(dados_original);
        return 1;
    }

    testar_heap_sort_texto("Caso 1: Original → Crescente", dados_original, n, 0);

    
    testar_heap_sort_texto("Caso 2: Original → Decrescente", dados_original, n, 1);

    char **ordenado_crescente = malloc(n * sizeof(char *));
    copiar_dados(ordenado_crescente, dados_original, n);
    unsigned long long int trocas_tmp = 0;
    heap_sort_crescente(ordenado_crescente, n, &trocas_tmp);

    testar_heap_sort_texto("Caso 3: Crescente → Decrescente", ordenado_crescente, n, 1);
    liberar_dados_texto(ordenado_crescente, n);
    free(ordenado_crescente);

    liberar_dados_texto(dados_original, n);
    free(dados_original);

    return 0;
}

