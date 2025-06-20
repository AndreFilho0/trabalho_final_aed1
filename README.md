#  Projeto de AED1 - Heap Sort e selection sort
#  Projeto feito pelos alunos : André de oliveira machado filho e João Victor Borges Tavares
## 1. Gerando Arquivos de Teste

### Dados Numéricos e Textuais Aleatórios
```bash
cd dados_de_entrada/numericos
gcc gerar_numeros.c -o dados_entrada_numerico.out
./dados_entrada_numerico.out
cd ../..
cd dados_de_entrada/textuais
gcc textos_aleatorios.c -o dados_entrada_textual.out
./dados_entrada_textual.out
```

## 2. Compilando o Algoritmo Heap Sort parte numérica
```bash
gcc Heap_Sort/numerico/main_vetor.c Heap_Sort/numerico/heap_sort.c -o heap_sort_numerico.out
./heap_sort_numerico.out
```

## 3. Compilando o Algoritmo Heap Sort parte textual
```bash
gcc Heap_Sort/textual/main_vetor.c Heap_Sort/textual/heap_sort.c -o heap_sort_textual.out
./heap_sort_textual.out
```

### Observação: Gere os arquivos de entrada antes de executar os programas de ordenação.

