#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_NOMES 1000000


void gerar_nome(char *nome, int tamanho) {
    const char letras[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < tamanho; i++) {
        nome[i] = letras[rand() % 26];
    }
    nome[tamanho] = '\0';
}

int main() {
    FILE *arquivo;
    char nome[ 8 ]; 
    char caminho[] = "nomes_aleatorios.txt";

    srand(420); 

    arquivo = fopen(caminho, "w");
    if (!arquivo) {
        perror("Erro ao criar o arquivo de nomes");
        return 1;
    }

    for (int i = 0; i < TOTAL_NOMES; i++) {
        int tamanho = 8;
        gerar_nome(nome, tamanho);
        fprintf(arquivo, "%s\n", nome);
    }

    fclose(arquivo);
    printf("Arquivo '%s' gerado com sucesso (%d nomes).\n", caminho, TOTAL_NOMES);
    return 0;
}

