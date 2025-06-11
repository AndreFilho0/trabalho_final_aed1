#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap_sort.h" 

#define MAX_NUMBERS 100

int main() {
    FILE *arquivo;
    char *nome_arquivo = "../../dados_de_entrada/numericos/dados_aleatorio_10.txt"; 

    int dados[MAX_NUMBERS];
    int count = 0;

    
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Certifique-se de que o arquivo '%s' existe no caminho correto em relação ao executável.\n", nome_arquivo);
        return 1;
    }

    
    printf("Lendo dados do arquivo '%s':\n", nome_arquivo);
    while (count < MAX_NUMBERS && fscanf(arquivo, "%d", &dados[count]) == 1) {
        printf("%d\n", dados[count]);
        count++;
    }
    fclose(arquivo);

    printf("\nDados lidos (%d elementos):\n", count);
    imprimir_array(dados, count);

    
    printf("\nRealizando Heap Sort...\n");
    heap_sort(dados, count);

    
    printf("\nArray ordenado:\n");
    imprimir_array(dados, count);

   

    return 0;
}
