# Análise Empírica de Métricas de Ordenação

Este documento apresenta os resultados empíricos de testes de ordenação em diferentes cenários e tamanhos de dados.

## Casos de Teste

### 1. Ordenação de Dados Já Ordenados em Ordem Crescente → Crescente

| Tamanho | Tempo (s)     | Trocas       | Primeiros Elementos (Ordenados)          |
|---------|---------------|--------------|------------------------------------------|
| 10      | 0.0000060     | 30           | 1 2 3 4 5 6 7 8 9 10                     |
| 100     | 0.0000240     | 640          | 1 2 3 ... 20                             |
| 1,000   | 0.0002510     | 9,708        | 1 2 3 ... 20                             |
| 10,000  | 0.0033960     | 131,956      | 1 2 3 ... 20                             |
| 100,000 | 0.0430140     | 1,650,854    | 1 2 3 ... 20                             |
| 1M      | 0.3171820     | 19,787,792   | 1 2 3 ... 20                             |
| 10M     | 3.5986860     | 231,881,708  | 1 2 3 ... 20                             |
| 100M    | 39.8949720    | 2,652,454,802| 1 2 3 ... 20                             |

### 2. Ordenação de Dados Aleatórios → Crescente

| Tamanho | Tempo (s)     | Trocas       | Primeiros Elementos (Ordenados)          |
|---------|---------------|--------------|------------------------------------------|
| 10      | 0.0000030     | 27           | 5136076 73478952 ... 2091243229          |
| 100     | 0.0000150     | 584          | 5136076 23149027 ... 444835065           |
| 1,000   | 0.0001920     | 9,084        | 5136076 5607661 ... 47472618             |
| 10,000  | 0.0030320     | 124,194      | 596055 597860 ... 4502919                |
| 100,000 | 0.0361390     | 1,575,030    | 9933 57368 ... 617784                    |
| 1M      | 0.4662420     | 19,048,368   | 272 1165 ... 40543                       |
| 10M     | 6.3665680     | 223,836,447  | 216 272 ... 3508                         |
| 100M    | 88.4744070    | 2,571,583,550| 58 72 ... 430                            |

### 3. Ordenação de Dados Já Ordenados em Ordem Crescente → Decrescente

| Tamanho | Tempo (s)     | Trocas       | Primeiros Elementos (Ordenados)          |
|---------|---------------|--------------|------------------------------------------|
| 10      | 0.0000030     | 21           | 10 9 8 ... 1                             |
| 100     | 0.0000140     | 516          | 100 99 ... 81                            |
| 1,000   | 0.0001750     | 8,316        | 1000 999 ... 981                         |
| 10,000  | 0.0026070     | 116,696      | 10000 9999 ... 9981                      |
| 100,000 | 0.0319030     | 1,497,434    | 100000 99999 ... 99981                   |
| 1M      | 0.3681550     | 18,333,408   | 1000000 999999 ... 999981                |
| 10M     | 3.9698390     | 216,912,428  | 10000000 9999999 ... 9999981             |
| 100M    | 40.9332120    | 2,500,251,420| 100000000 99999999 ... 99999981           |

## Observações

1. **Dados Já Ordenados (Crescente → Crescente)**:
   - O número de trocas é significativo mesmo para dados já ordenados
   - O tempo de execução cresce de forma aproximadamente linear com o tamanho dos dados

2. **Dados Aleatórios**:
   - O número de trocas é menor do que para dados já ordenados em casos pequenos, mas ultrapassa nos casos maiores
   - O tempo de execução mostra comportamento O(n log n) típico de algoritmos eficientes

3. **Ordenação Inversa (Crescente → Decrescente)**:
   - O número de trocas é menor do que para ordenação crescente
   - Os tempos são ligeiramente menores que na ordenação crescente

4. **Escalabilidade**:
   - O algoritmo mostra boa escalabilidade, com tempos razoáveis mesmo para 100 milhões de elementos
   - O aumento no número de trocas é aproximadamente linear com o tamanho dos dados
