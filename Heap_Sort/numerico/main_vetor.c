#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap_sort.h"
#include <time.h>

#define MAX_NUMEROS 100000000 


int ler_dados(const char *caminho, int *dados) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Verifique o caminho: %s\n", caminho);
        return -1;
    }

    int count = 0;
    while (fscanf(arquivo, "%d", &dados[count]) == 1 && count < MAX_NUMEROS) {
        count++;
    }
    fclose(arquivo);
    return count;
}


void testar_heap_sort(const char *descricao, const char *caminho_arquivo, int decrescente) {
    int *dados = malloc(MAX_NUMEROS * sizeof(int));
    if (!dados) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    int n = ler_dados(caminho_arquivo, dados);
    if (n <= 0) {
        free(dados);
        return;
    }

    printf("\n\n--- %s ----\n", descricao);
    printf("Arquivo: %s\n", caminho_arquivo);
    printf("Quantidade de elementos: %d\n", n);
    
    clock_t inicio = clock();
     unsigned long long int contador_trocas = 0;
    if (decrescente) {
        printf("Ordenando em ordem DECRESCENTE...\n");
        heap_sort_decrescente(dados, n , &contador_trocas);
        
    } else {
        printf("Ordenando em ordem CRESCENTE...\n");
        heap_sort_crescente(dados, n , &contador_trocas);
      
    }
     clock_t fim = clock();
     double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
     printf("Tempo de execução: %.7f segundos\n", tempo);
     printf("Número de trocas: %lld\n", contador_trocas);

    int exibir = n > 20 ? 20 : n;
    printf("Primeiros %d elementos após ordenação:\n", exibir);
    for (int i = 0; i < exibir; i++) {
        printf("%d ", dados[i]);
    }
    printf("\n");

    free(dados);
}

int main() {
    
    testar_heap_sort(
        "Caso 1 : Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_10.txt",
        0
    );
  testar_heap_sort(
        "Caso 2: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_100.txt",
        0
    );
  testar_heap_sort(
        "Caso 3: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_1000.txt",
        0
    );
  testar_heap_sort(
        "Caso 4: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_10000.txt",
        0
    );
  testar_heap_sort(
        "Caso 5: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_100000.txt",
        0
    );
  testar_heap_sort(
        "Caso 6: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_1000000.txt",
        0
    );
  testar_heap_sort(
        "Caso 7: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_10000000.txt",
        0
    );
  testar_heap_sort(
        "Caso 8: Ordenado Crescente → Crescente",
        "dados_de_entrada/numericos/dados_crescente_100000000.txt",
        0
    );

    // ----------------------------------------------------------------------- //   
  

   testar_heap_sort(
        "Caso 1 : Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_10.txt",
        0
    );
  testar_heap_sort(
        "Caso 2: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_100.txt",
        0
    );
  testar_heap_sort(
        "Caso 3: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_1000.txt",
        0
    );
  testar_heap_sort(
        "Caso 4: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_10000.txt",
        0
    );
  testar_heap_sort(
        "Caso 5: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_100000.txt",
        0
    );
  testar_heap_sort(
        "Caso 6: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_1000000.txt",
        0
    );
  testar_heap_sort(
        "Caso 7: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_10000000.txt",
        0
    );
  testar_heap_sort(
        "Caso 8: Ordenado Aleatório → Crescente",
        "dados_de_entrada/numericos/dados_aleatorio_100000000.txt",
        0
    );
   


   // ----------------------------------------------------------------------- //
  
   testar_heap_sort(
        "Caso 1 : Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_10.txt",
        1
    );
  testar_heap_sort(
        "Caso 2: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_100.txt",
        1
    );
  testar_heap_sort(
        "Caso 3: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_1000.txt",
        1
    );
  testar_heap_sort(
        "Caso 4: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_10000.txt",
        1
    );
  testar_heap_sort(
        "Caso 5: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_100000.txt",
        1
    );
  testar_heap_sort(
        "Caso 6: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_1000000.txt",
        1
    );
  testar_heap_sort(
        "Caso 7: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_10000000.txt",
        1
    );
  testar_heap_sort(
        "Caso 8: Ordenado Crescente → Decrescente",
        "dados_de_entrada/numericos/dados_crescente_100000000.txt",
        1
    );

    return 0;
}

