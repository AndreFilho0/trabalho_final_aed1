# Análise Empírica de Métricas de Ordenação (Selection Sort - Vetor)

Este documento apresenta os resultados empíricos de testes de ordenação com o algoritmo **Selection Sort** em diferentes cenários e tamanhos de dados, utilizando uma implementação baseada em vetor.

## Casos de Teste

### 1. Ordenação de Dados Já Ordenados em Ordem Crescente → Crescente

| Tamanho     | Tempo (s)   | Trocas | Primeiros Elementos (Ordenados) |
| :---------- | :---------- | :----- | :------------------------------ |
| 10          | 0.0000020   | 0      | 1 2 3 4 5 6 7 8 9 10            |
| 100         | 0.0000130   | 0      | 1 2 3 ... 20                    |
| 1.000       | 0.0007240   | 0      | 1 2 3 ... 20                    |
| 10.000      | 0.0765580   | 0      | 1 2 3 ... 20                    |
| 100.000     | 4.2839210   | 0      | 1 2 3 ... 20                    |
| 1.000.000   | 432.6217190 | 0      | 1 2 3 ... 20                    |
| 10.000.000  | \~12 horas  | 0      | (não executado)                 |
| 100.000.000 | \~50 dias   | 0      | (não executado)                 |

### 2. Ordenação de Dados Aleatórios → Crescente

| Tamanho     | Tempo (s)   | Trocas     | Primeiros Elementos (Ordenados) |
| :---------- | :---------- | :--------- | :------------------------------ |
| 10          | 0.0000040   | 5          | 5136076 73478952 ... 2091243229 |
| 100         | 0.0000110   | 94         | 5136076 23149027 ... 444835065  |
| 1.000       | 0.0005590   | 994        | 5136076 5607661 ... 47472618    |
| 10.000      | 0.0742650   | 9.988      | 596055 597860 ... 4502919       |
| 100.000     | 4.2380680   | 99.987     | 9933 57368 ... 617784           |
| 1.000.000   | 427.1488810 | 999.980    | 272 1165 ... 40543              |
| 10.000.000  | \~12 horas  | 9.999.999  | (estimado)                      |
| 100.000.000 | \~50 dias   | 99.999.999 | (estimado)                      |

### 3. Ordenação de Dados Já Ordenados em Ordem Crescente → Decrescente

| Tamanho     | Tempo (s)   | Trocas     | Primeiros Elementos (Ordenados) |
| :---------- | :---------- | :--------- | :------------------------------ |
| 10          | 0.0000040   | 5          | 10 9 8 ... 1                    |
| 100         | 0.0000160   | 50         | 100 99 ... 81                   |
| 1.000       | 0.0011190   | 500        | 1000 999 ... 981                |
| 10.000      | 0.0822190   | 5.000      | 10000 9999 ... 9981             |
| 100.000     | 4.4191140   | 50.000     | 100000 99999 ... 99981          |
| 1.000.000   | 441.7858740 | 500.000    | 1000000 999999 ... 999981       |
| 10.000.000  | \~12 horas  | 5.000.000  | (estimado)                      |
| 100.000.000 | \~50 dias   | 50.000.000 | (estimado)                      |

## Observações

1. **Dados Já Ordenados (Crescente → Crescente):**

   * O número de trocas é **zero**, como esperado. Este é o melhor caso para trocas.
   * O tempo de execução **não melhora** significativamente. Isso ocorre porque o algoritmo sempre executa o mesmo número de comparações (dois laços aninhados), independentemente da ordem inicial dos dados.

2. **Dados Aleatórios:**

   * O número de trocas é alto, próximo de `n`, indicando que quase todos os elementos precisaram ser movidos para sua posição correta.
   * O tempo de execução é muito similar aos outros cenários, confirmando o comportamento **O(n²)**, que é típico do Selection Sort e o torna ineficiente para grandes volumes.

3. **Ordenação Inversa (Crescente → Decrescente):**

   * O número de trocas é previsivelmente `n/2`, pois cada elemento na primeira metade é trocado com seu correspondente na segunda metade.
   * Os tempos de execução são, novamente, quase idênticos aos outros casos, demonstrando a insensibilidade do algoritmo à ordem dos dados em termos de tempo.

4. **Escalabilidade:**

   * O algoritmo mostra **baixa escalabilidade**. O tempo de execução cresce de forma **quadrática (O(n²))**, tornando-o extremamente lento e impraticável para entradas grandes (acima de 100.000 elementos).
   * A não execução para 10 e 100 milhões de elementos evidencia essa limitação. O aumento no número de trocas, por outro lado, é linear (`O(n)`).
