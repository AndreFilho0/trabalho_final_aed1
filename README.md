# trabalho_final_aed1
# doc pessoal do grupo 
# Tabela com o que vai ser feito no trabalho de forma geral
base da estrutura do projeto , pode seguir essa ideia ? 
```
── dados_de_entrada
│   ├── numericos
│   │   ├── dados_aleatorio_100000000.txt
│   │   ├── dados_aleatorio_10000000.txt
│   │   ├── dados_aleatorio_1000000.txt
│   │   ├── dados_aleatorio_100000.txt
│   │   ├── dados_aleatorio_10000.txt
│   │   ├── dados_aleatorio_1000.txt
│   │   ├── dados_aleatorio_100.txt
│   │   ├── dados_aleatorio_10.txt
│   │   ├── dados_crescente_100000000.txt
│   │   ├── dados_crescente_10000000.txt
│   │   ├── dados_crescente_1000000.txt
│   │   ├── dados_crescente_100000.txt
│   │   ├── dados_crescente_10000.txt
│   │   ├── dados_crescente_1000.txt
│   │   ├── dados_crescente_100.txt
│   │   ├── dados_crescente_10.txt
│   │   ├── dados_decrescente_100000000.txt
│   │   ├── dados_decrescente_10000000.txt
│   │   ├── dados_decrescente_1000000.txt
│   │   ├── dados_decrescente_100000.txt
│   │   ├── dados_decrescente_10000.txt
│   │   ├── dados_decrescente_1000.txt
│   │   ├── dados_decrescente_100.txt
│   │   ├── dados_decrescente_10.txt
│   │   └── gerar_numeros.c
│   └── textuais
│       ├── nomes_aleatorios.txt
│       └── textos_aleatorios.c
├── Heap_Sort
│   └── numerico
│       ├── heap_sort.c
│       ├── heap_sort.h
│       ├── heap_sort_numerico.out
│       └── main.c
└── README.md
``


| Algoritmo      | Estrutura de Dados    | Tipo de Dado | Casos de Teste                                                                                                                    |
| -------------- | --------------------- | ------------ | --------------------------------------------------------------------------------------------------------------------------------- |
| Selection Sort | Vetor                 | Numérico     | 1. Ordenado crescente → ordenar crescente<br>2. Aleatório → ordenar crescente<br>3. Ordenado crescente → ordenar decrescente      |
| Selection Sort | Lista duplamente enc. | Numérico     | 1. Ordenado crescente → ordenar crescente<br>2. Aleatório → ordenar crescente<br>3. Ordenado crescente → ordenar decrescente      |
| Heap Sort      | Vetor                 | Numérico     | 1. Ordenado crescente → ordenar crescente<br>2. Aleatório → ordenar crescente<br>3. Ordenado crescente → ordenar decrescente      |
| Heap Sort      | Lista (via conversão) | Numérico     | 1. Ordenado crescente → ordenar crescente<br>2. Aleatório → ordenar crescente<br>3. Ordenado crescente → ordenar decrescente      |
| Selection Sort | Vetor                 | Textual      | 1. Estado original → ordenar crescente<br>2. Estado original → ordenar decrescente<br>3. Ordenado crescente → ordenar decrescente |
| Selection Sort | Lista duplamente enc. | Textual      | 1. Estado original → ordenar crescente<br>2. Estado original → ordenar decrescente<br>3. Ordenado crescente → ordenar decrescente |
| Heap Sort      | Vetor                 | Textual      | 1. Estado original → ordenar crescente<br>2. Estado original → ordenar decrescente<br>3. Ordenado crescente → ordenar decrescente |
| Heap Sort      | Lista (via conversão) | Textual      | 1. Estado original → ordenar crescente<br>2. Estado original → ordenar decrescente<br>3. Ordenado crescente → ordenar decrescente |



# mais ou menos como vai ser formatado os resultados : 
| Algoritmo      | Estrutura         | Tipo de Dado | Tempo Execução (empírico) | Trocas (empírico) | Complexidade Teórica (matemática)   |
| -------------- | ----------------- | ------------ | ------------------------- | ----------------- | ----------------------------------- |
| Selection Sort | Vetor             | Numérico     | xx ms                     | xx trocas         | O(n²)                               |
| Selection Sort | Lista Duplamente  | Numérico     | xx ms                     | xx trocas         | O(n²), acesso sequencial            |
| Heap Sort      | Vetor             | Numérico     | xx ms                     | xx trocas         | O(n log n)                          |
| Heap Sort      | Lista (conversão) | Numérico     | xx ms                     | xx trocas         | O(n log n), mas conversão pesa      |
| Selection Sort | Vetor             | Textual      | xx ms                     | xx trocas         | O(n²)                               |
| Selection Sort | Lista Duplamente  | Textual      | xx ms                     | xx trocas         | O(n²), com impacto do acesso linear |
| Heap Sort      | Vetor             | Textual      | xx ms                     | xx trocas         | O(n log n)                          |
| Heap Sort      | Lista (conversão) | Textual      | xx ms                     | xx trocas         | O(n log n), com sobrecarga extra    |



### Para cada algoritmo e tipo de implementação, deve ser gerado um gráfico evidenciando o comportamento dos dados e soluções
- vai ser preciso fazer então varios testes e fazer um plot do grafico com media desvio padrão  ?
