#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heap_sort.h"

Lista* ler_lista(const char *caminho) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Verifique o caminho: %s\n", caminho);
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

void testar_heap_sort_lista(const char *descricao, const char *caminho_arquivo, int decrescente) {
    Lista *lista = ler_lista(caminho_arquivo);
    if (!lista) return;

    printf("\n\n--- %s ----\n", descricao);
    printf("Arquivo: %s\n", caminho_arquivo);
    printf("Quantidade de elementos: %d\n", lista->tamanho);

    clock_t inicio = clock();
    unsigned long long int contador_trocas = 0;

    if (decrescente) {
        printf("Ordenando em ordem DECRESCENTE...\n");
        heap_sort_decrescente_lista(lista, &contador_trocas);
    } else {
        printf("Ordenando em ordem CRESCENTE...\n");
        heap_sort_crescente_lista(lista, &contador_trocas);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.7f segundos\n", tempo);
    printf("Número de trocas: %llu\n", contador_trocas);

    printf("Primeiros elementos após ordenação:\n");
    No *atual = lista->inicio;
    for (int i = 0; i < 20 && atual != NULL; i++) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");

    destruir_lista(lista);
}

int main() {
    
   // testar_heap_sort_lista("Lista - Caso 1: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_10.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 2: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_100.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 3: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_1000.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 4: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_10000.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 5: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_100000.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 6: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_1000000.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 7: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_10000000.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 8: Crescente → Crescente", "../../dados_de_entrada/numericos/dados_crescente_100000000.txt", 0);

    // ----------------------------------------------------------------------- //   

  //  testar_heap_sort_lista("Lista - Caso 1: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_10.txt", 0);
  //  testar_heap_sort_lista("Lista - Caso 2: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_100.txt", 0);
  //  testar_heap_sort_lista("Lista - Caso 3: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_1000.txt", 0);
  //  testar_heap_sort_lista("Lista - Caso 4: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_10000.txt", 0);
  //  testar_heap_sort_lista("Lista - Caso 5: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_100000.txt", 0);
  //  testar_heap_sort_lista("Lista - Caso 6: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_1000000.txt", 0);
  //  testar_heap_sort_lista("Lista - Caso 7: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_10000000.txt", 0);
   // testar_heap_sort_lista("Lista - Caso 8: Aleatório → Crescente", "../../dados_de_entrada/numericos/dados_aleatorio_100000000.txt", 0);

    // ----------------------------------------------------------------------- //   

    testar_heap_sort_lista("Lista - Caso 1: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_10.txt", 1);
    testar_heap_sort_lista("Lista - Caso 2: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_100.txt", 1);
    testar_heap_sort_lista("Lista - Caso 3: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_1000.txt", 1);
    testar_heap_sort_lista("Lista - Caso 4: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_10000.txt", 1);
    testar_heap_sort_lista("Lista - Caso 5: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_100000.txt", 1);
    testar_heap_sort_lista("Lista - Caso 6: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_1000000.txt", 1);
    testar_heap_sort_lista("Lista - Caso 7: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_10000000.txt", 1);
    testar_heap_sort_lista("Lista - Caso 8: Crescente → Decrescente", "dados_de_entrada/numericos/dados_crescente_100000000.txt", 1);

    return 0;
}

