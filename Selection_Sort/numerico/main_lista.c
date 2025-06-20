#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection_sort.h"

Lista* ler_lista(const char *caminho) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Caminho verificado: %s\n", caminho);
        return NULL;
    }
    Lista *lista = criar_lista();
    int valor;
    while (fscanf(arquivo, "%d", &valor) == 1) {
        inserir_final(lista, valor);
    }
    fclose(arquivo);
    return lista;
}

void testar_selection_sort_lista(const char *descricao, const char *caminho_arquivo, int decrescente) {
    Lista *lista = ler_lista(caminho_arquivo);
    if (!lista) return;

    printf("\n--- Selection Sort (Lista) | %s ---\n", descricao);
    printf("Arquivo: %s\n", caminho_arquivo);
    printf("Quantidade de elementos: %d\n", lista->tamanho);

    clock_t inicio = clock();
    unsigned long long int contador_trocas = 0;

    if (decrescente) {
        printf("Ordenando em ordem DECRESCENTE...\n");
        selection_sort_lista_decrescente(lista, &contador_trocas);
    } else {
        printf("Ordenando em ordem CRESCENTE...\n");
        selection_sort_lista_crescente(lista, &contador_trocas);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.7f segundos\n", tempo);
    printf("Numero de trocas: %llu\n", contador_trocas);

    printf("Primeiros elementos apos ordenacao:\n");
    imprimir_lista(lista, 20);

    destruir_lista(lista);
}

int main() {
    printf("========================================================\n");
    printf("INICIANDO TESTES - SELECTION SORT - LISTA\n");
    printf("========================================================\n");
    
    int tamanhos[] = {10, 100, 1000, 10000, 100000,1000000,10000000,100000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        char caminho_crescente[256];
        char caminho_aleatorio[256];
        
        snprintf(caminho_crescente, sizeof(caminho_crescente), "../../dados_de_entrada/numericos/dados_crescente_%d.txt", n);
        snprintf(caminho_aleatorio, sizeof(caminho_aleatorio), "../../dados_de_entrada/numericos/dados_aleatorio_%d.txt", n);

        testar_selection_sort_lista("Crescente -> Crescente", caminho_crescente, 0);
        testar_selection_sort_lista("Aleatorio -> Crescente", caminho_aleatorio, 0);
        testar_selection_sort_lista("Crescente -> Decrescente", caminho_crescente, 1);
    }
    
    printf("\n========================================================\n");
    printf("FIM DOS TESTES - SELECTION SORT - LISTA\n");
    printf("========================================================\n");

    return 0;
}