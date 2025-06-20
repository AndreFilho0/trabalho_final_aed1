#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "selection_sort_textual.h"

#define MAX_TAMANHO_NOME 100 

ListaTextual* ler_dados_lista(const char *caminho) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de nomes");
        return NULL;
    }

    ListaTextual *lista = criar_lista_textual();
    char buffer[MAX_TAMANHO_NOME];
    
    while (fgets(buffer, sizeof(buffer), arquivo)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        inserir_final_textual(lista, buffer);
    }

    fclose(arquivo);
    return lista;
}

void testar_selection_sort_lista_textual(const char *descricao, const char *caminho_arquivo, int decrescente_inicial, int decrescente_final) {
    ListaTextual *lista = ler_dados_lista(caminho_arquivo);
    if (!lista) return;

    printf("\n--- Selection Sort (Lista Textual) | %s ---\n", descricao);
    printf("Arquivo: %s | Quantidade: %d\n", caminho_arquivo, lista->tamanho);

    unsigned long long int contador_trocas = 0;
    
    if (decrescente_inicial != -1) { 
        if (decrescente_inicial) {
             selection_sort_lista_decrescente_textual(lista, &contador_trocas);
        } else {
             selection_sort_lista_crescente_textual(lista, &contador_trocas);
        }
    }

    printf("Ordenando...\n");
    contador_trocas = 0; 
    clock_t inicio = clock();

    if (decrescente_final) {
        selection_sort_lista_decrescente_textual(lista, &contador_trocas);
    } else {
        selection_sort_lista_crescente_textual(lista, &contador_trocas);
    }
    
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.7f segundos\n", tempo);
    printf("Numero de trocas: %llu\n", contador_trocas);

    printf("Primeiros 20 nomes apos ordenacao:\n");
    imprimir_lista_textual(lista, 20);

    destruir_lista_textual(lista);
}


int main() {
    const char *caminho_nomes = "../../dados_de_entrada/textuais/nomes_aleatorios.txt";
    
    printf("========================================================\n");
    printf("INICIANDO TESTES - SELECTION SORT - LISTA TEXTUAL\n");
    printf("========================================================\n");

    testar_selection_sort_lista_textual("Original -> Crescente", caminho_nomes, -1, 0);

    testar_selection_sort_lista_textual("Original -> Decrescente", caminho_nomes, -1, 1);

    testar_selection_sort_lista_textual("Crescente -> Decrescente", caminho_nomes, 0, 1);
    
    printf("\n========================================================\n");
    printf("FIM DOS TESTES - SELECTION SORT - LISTA TEXTUAL\n");
    printf("========================================================\n");
    
    return 0;
}