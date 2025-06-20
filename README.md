#  Projeto de AED1 - Heap Sort e selection sort
#  Projeto feito pelos alunos : André de oliveira machado filho e João Victor Borges Tavares
## github : https://github.com/AndreFilho0/trabalho_final_aed1
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

# --- COMPILAR E EXECUTAR SELECTION SORT NUMÉRICO ---

(cd Selection_Sort/numerico && gcc main_vetor.c selection_sort.c -o main_vetor.out -Wall && ./main_vetor.out)
(cd Selection_Sort/numerico && gcc main_lista.c selection_sort.c -o main_lista.out -Wall && ./main_lista.out)

# --- COMPILAR E EXECUTAR SELECTION SORT TEXTUAL ---

(cd Selection_Sort/textual && gcc main_vetor_textual.c selection_sort_textual.c -o main_vetor_textual.out -Wall && ./main_vetor_textual.out)
(cd Selection_Sort/textual && gcc main_lista_textual.c selection_sort_textual.c -o main_lista_textual.out -Wall && ./main_lista_textual.out)

### Observação: Gere os arquivos de entrada antes de executar os programas de ordenação.

