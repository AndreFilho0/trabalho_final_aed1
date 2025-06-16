#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection_sort.h"

Lista* ler_lista(const char *caminho) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
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
    
    testar_selection_sort_lista("Crescente -> Crescente", "../../dados_de_entrada/numericos/dados_crescente_10000.txt", 0);
    
    testar_selection_sort_lista("Aleatorio -> Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_10000.txt", 0);

    testar_selection_sort_lista("Crescente -> Decrescente", "../../dados_de_entrada/numericos/dados_crescente_10000.txt", 1);
    
    printf("\n========================================================\n");
    printf("FIM DOS TESTES - SELECTION SORT - LISTA\n");
    printf("========================================================\n");

    return 0;
}