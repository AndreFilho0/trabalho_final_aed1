#include <stdio.h>
#include <stdlib.h>

void gerar_crescente(int n, const char* nome_arquivo) {
    FILE* f = fopen(nome_arquivo, "w");
    if (!f) {
        perror("Erro ao criar arquivo crescente");
        return;
    }
    for (int i = 1; i <= n; i++) {
        fprintf(f, "%d\n", i);
    }
    fclose(f);
}

void gerar_decrescente(int n, const char* nome_arquivo) {
    FILE* f = fopen(nome_arquivo, "w");
    if (!f) {
        perror("Erro ao criar arquivo decrescente");
        return;
    }
    for (int i = n; i >= 1; i--) {
        fprintf(f, "%d\n", i);
    }
    fclose(f);
}

void gerar_aleatorio(int n, const char* nome_arquivo) {
    FILE* f = fopen(nome_arquivo, "w");
    if (!f) {
        perror("Erro ao criar arquivo aleatorio");
        return;
    }

    srand(420); 
    for (int i = 0; i < n; i++) {
        int r = rand(); 
    fprintf(f, "%d\n", r);
    }
    fclose(f);
}

int main() {
    int tamanhos[] = {
        10, 100, 1000, 10000, 100000,
        1000000, 10000000, 100000000
    };

    int qtd_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < qtd_tamanhos; i++) {
        int n = tamanhos[i];
        char nome_crescente[64];
        char nome_decrescente[64];
        char nome_aleatorio[64];

        snprintf(nome_crescente, sizeof(nome_crescente), "dados_crescente_%d.txt", n);
        snprintf(nome_decrescente, sizeof(nome_decrescente), "dados_decrescente_%d.txt", n);
        snprintf(nome_aleatorio, sizeof(nome_aleatorio), "dados_aleatorio_%d.txt", n);

        printf("Gerando arquivos com %d elementos...\n", n);

        gerar_crescente(n, nome_crescente);
        gerar_decrescente(n, nome_decrescente);
        gerar_aleatorio(n, nome_aleatorio);
    }

    printf("Todos os arquivos foram gerados com sucesso.\n");

    return 0;
}

