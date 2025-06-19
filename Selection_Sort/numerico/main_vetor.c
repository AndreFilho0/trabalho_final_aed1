#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection_sort.h"

#define MAX_NUMEROS 100000  

int ler_dados(const char *caminho, int *dados) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Caminho verificado: %s\n", caminho);
        return -1;
    }
    int count = 0;
    while (fscanf(arquivo, "%d", &dados[count]) == 1 && count < MAX_NUMEROS) {
        count++;
    }
    fclose(arquivo);
    return count;
}

void testar_selection_sort_vetor(const char *descricao, const char *caminho_arquivo, int decrescente) {
    int *dados = malloc(MAX_NUMEROS * sizeof(int));
    if (!dados) {
        fprintf(stderr, "Erro de alocacao de memoria.\n");
        return;
    }

    int n = ler_dados(caminho_arquivo, dados);
    if (n <= 0) {
        free(dados);
        return;
    }

    printf("\n--- Selection Sort (Vetor) | %s ---\n", descricao);
    printf("Arquivo: %s\n", caminho_arquivo);
    printf("Quantidade de elementos: %d\n", n);
    
    clock_t inicio = clock();
    unsigned long long int contador_trocas = 0;

    if (decrescente) {
        printf("Ordenando em ordem DECRESCENTE...\n");
        selection_sort_vetor_decrescente(dados, n, &contador_trocas);
    } else {
        printf("Ordenando em ordem CRESCENTE...\n");
        selection_sort_vetor_crescente(dados, n, &contador_trocas);
    }
    
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.7f segundos\n", tempo);
    printf("Numero de trocas: %llu\n", contador_trocas);

    int exibir = n > 20 ? 20 : n;
    printf("Primeiros %d elementos apos ordenacao:\n", exibir);
    for (int i = 0; i < exibir; i++) {
        printf("%d ", dados[i]);
    }
    printf("\n");

    free(dados);
}

int main() {
    printf("========================================================\n");
    printf("INICIANDO TESTES - SELECTION SORT - VETOR\n");
    printf("========================================================\n");

    int tamanhos[] = {10, 100, 1000, 10000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        char caminho_crescente[256];
        char caminho_aleatorio[256];
        
        snprintf(caminho_crescente, sizeof(caminho_crescente), "../../dados_de_entrada/numericos/dados_crescente_%d.txt", n);
        snprintf(caminho_aleatorio, sizeof(caminho_aleatorio), "../../dados_de_entrada/numericos/dados_aleatorio_%d.txt", n);

        testar_selection_sort_vetor("Crescente -> Crescente", caminho_crescente, 0);
        testar_selection_sort_vetor("Aleatorio -> Crescente", caminho_aleatorio, 0);
        testar_selection_sort_vetor("Crescente -> Decrescente", caminho_crescente, 1);
    }
    
    printf("\n========================================================\n");
    printf("FIM DOS TESTES - SELECTION SORT - VETOR\n");
    printf("========================================================\n");

    return 0;
}