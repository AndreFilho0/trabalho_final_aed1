#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "selection_sort_textual.h"

#define MAX_NOMES 1000000
#define MAX_TAMANHO_NOME 100 

int ler_dados_vetor(const char *caminho, char **dados) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de nomes");
        return -1;
    }

    int count = 0;
    char buffer[MAX_TAMANHO_NOME];
    while (fgets(buffer, sizeof(buffer), arquivo) && count < MAX_NOMES) {
        buffer[strcspn(buffer, "\n")] = '\0';
        dados[count] = strdup(buffer); 
        if (dados[count] == NULL) {
            fprintf(stderr, "Erro de alocacao de memoria para nome.\n");
            break; 
        }
        count++;
    }

    fclose(arquivo);
    return count;
}

void liberar_dados_vetor(char **dados, int n) {
    if (!dados) return;
    for (int i = 0; i < n; i++) {
        free(dados[i]);
    }
    free(dados);
}

void testar_selection_sort_vetor_textual(const char *descricao, const char *caminho_arquivo, int decrescente_inicial, int decrescente_final) {
    char **dados = malloc(MAX_NOMES * sizeof(char*));
    if (!dados) {
        fprintf(stderr, "Erro de alocacao de memoria principal.\n");
        return;
    }

    int n = ler_dados_vetor(caminho_arquivo, dados);
    if (n <= 0) {
        liberar_dados_vetor(dados, 0);
        return;
    }

    printf("\n--- Selection Sort (Vetor Textual) | %s ---\n", descricao);
    printf("Arquivo: %s | Quantidade: %d\n", caminho_arquivo, n);

    unsigned long long int contador_trocas = 0;

    if (decrescente_inicial != -1) { 
        if (decrescente_inicial) {
             selection_sort_vetor_decrescente_textual(dados, n, &contador_trocas);
        } else {
             selection_sort_vetor_crescente_textual(dados, n, &contador_trocas);
        }
    }
    
    printf("Ordenando...\n");
    contador_trocas = 0; 
    clock_t inicio = clock();
    
    if (decrescente_final) {
        selection_sort_vetor_decrescente_textual(dados, n, &contador_trocas);
    } else {
        selection_sort_vetor_crescente_textual(dados, n, &contador_trocas);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.7f segundos\n", tempo);
    printf("Numero de trocas: %llu\n", contador_trocas);

    printf("Primeiros 20 nomes apos ordenacao:\n");
    for (int i = 0; i < 20 && i < n; i++) {
        printf("%s\n", dados[i]);
    }

    liberar_dados_vetor(dados, n);
}

int main() {
    const char *caminho_nomes = "../../dados_de_entrada/textuais/nomes_aleatorios.txt";
    
    printf("========================================================\n");
    printf("INICIANDO TESTES - SELECTION SORT - VETOR TEXTUAL\n");
    printf("========================================================\n");

    testar_selection_sort_vetor_textual("Original -> Crescente", caminho_nomes, -1, 0);

    testar_selection_sort_vetor_textual("Original -> Decrescente", caminho_nomes, -1, 1);

    testar_selection_sort_vetor_textual("Crescente -> Decrescente", caminho_nomes, 0, 1);
    
    printf("\n========================================================\n");
    printf("FIM DOS TESTES - SELECTION SORT - VETOR TEXTUAL\n");
    printf("========================================================\n");

    return 0;
}