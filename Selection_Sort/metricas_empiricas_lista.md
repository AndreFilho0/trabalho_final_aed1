# Análise Empírica de Métricas de Ordenação - Selection Sort (Lista)

Este documento apresenta os resultados empíricos de testes de ordenação com o algoritmo **Selection Sort**, utilizando uma estrutura de **lista duplamente encadeada**.

## Casos de Teste

### 1. Ordenação de Lista Crescente → Crescente

| Tamanho   | Tempo (s)               | Tempo Humano     | Trocas | Primeiros Elementos (Ordenados) |
| :-------- | :---------------------- | :--------------- | :----- | :------------------------------ |
| 10        | 0.0000050               | Instantâneo      | 0      | 1 2 3 ... 10                    |
| 100       | 0.0000090               | Instantâneo      | 0      | 1 2 3 ... 20                    |
| 1.000     | 0.0007150               | 0.001 segundos   | 0      | 1 2 3 ... 20                    |
| 10.000    | 0.0927730               | 0.09 segundos    | 0      | 1 2 3 ... 20                    |
| 100.000   | 6.8440800               | \~7 segundos     | 0      | 1 2 3 ... 20                    |
| 1.000.000 | 1071.7271220            | **\~18 minutos** | 0      | 1 2 3 ... 20                    |
| 10M       | (estimado) \~29,8 horas | (não executado)  | 0      | (não executado)                 |
| 100M      | (estimado) \~124 dias   | (não executado)  | 0      | (não executado)                 |

**Observações**:

* O tempo de execução cresce **quadraticamente (O(n²))**. A sobrecarga do acesso sequencial na lista torna o fator constante maior, mas a complexidade fundamental do algoritmo permanece a mesma.
* O número de trocas é **zero**, pois a lista já está ordenada.

### 2. Ordenação de Lista Aleatória → Crescente

| Tamanho   | Tempo (s)               | Tempo Humano     | Trocas     | Primeiros Elementos (Ordenados)  |
| :-------- | :---------------------- | :--------------- | :--------- | :------------------------------- |
| 10        | 0.0000020               | Instantâneo      | 5          | 5136076 73478952 ... 2091243229  |
| 100       | 0.0000150               | Instantâneo      | 94         | 5136076 23149027 ... 444835065   |
| 1.000     | 0.0009440               | 0.001 segundos   | 994        | 5136076 5607661 ... 47472618     |
| 10.000    | 0.0771650               | 0.08 segundos    | 9.988      | 596055 597860 ... 4502919        |
| 100.000   | 6.8243710               | \~7 segundos     | 99.987     | 9933 57368 ... 617784            |
| 1.000.000 | 1072.0005770            | **\~18 minutos** | 999.980    | \[padrão similar aos anteriores] |
| 10M       | (estimado) \~29,8 horas | (não executado)  | 9.999.999  | \[omissos por volume]            |
| 100M      | (estimado) \~124 dias   | (não executado)  | 99.999.999 | \[omissos por volume]            |

**Observações**:

* Os tempos são quase **idênticos** aos da lista já ordenada, confirmando que o desempenho do Selection Sort é insensível à ordem inicial dos dados.
* O número de trocas é `O(n)`, próximo de `n-1`, como esperado para dados aleatórios.

### 3. Ordenação Inversa de Lista Crescente → Decrescente

| Tamanho   | Tempo (s)               | Tempo Humano       | Trocas     | Primeiros Elementos (Ordenados) |
| :-------- | :---------------------- | :----------------- | :--------- | :------------------------------ |
| 10        | 0.0000030               | Instantâneo        | 5          | 10 9 8 ... 1                    |
| 100       | 0.0000170               | Instantâneo        | 50         | 100 99 ... 81                   |
| 1.000     | 0.0007400               | 0.001 segundos     | 500        | 1000 999 ... 981                |
| 10.000    | 0.0828550               | 0.08 segundos      | 5.000      | 10000 9999 ... 9981             |
| 100.000   | 6.9606880               | \~7 segundos       | 50.000     | 100000 99999 ... 99981          |
| 1.000.000 | 1050.4134280            | **\~17.5 minutos** | 500.000    | 1000000 999999 ... 999981       |
| 10M       | (estimado) \~29,2 horas | (não executado)    | 5.000.000  | 10000000 9999999 ... 9999981    |
| 100M      | (estimado) \~123 dias   | (não executado)    | 50.000.000 | 100000000 99999999 ... 99999981 |

**Observações**:

* A performance é praticamente a mesma dos outros cenários.
* O número de trocas é exatamente `n/2`, o que é consistente e previsível.

## Análise Comparativa

### Crescimento Temporal

![Gráfico de crescimento temporal](crescimento_temporal.png)
*(Inserir gráfico comparando os três cenários)*

O gráfico mostraria três linhas quase sobrepostas, ilustrando uma curva parabólica (quadrática), confirmando que o tempo de execução é independente da ordem inicial dos dados.

### Eficiência por Cenário

Diferentemente de outros algoritmos, o Selection Sort **não possui um "melhor" ou "pior" caso em termos de tempo de execução**.

1. **Melhor Caso (para trocas):** Lista já ordenada.

   * Número de trocas: 0
   * Tempo de execução: O(n²) (sem melhora)
2. **Caso Médio/Pior (para trocas):** Lista aleatória ou invertida.

   * Número de trocas: O(n) ou n/2
   * Tempo de execução: O(n²)

O desempenho temporal é consistentemente ruim para todas as entradas.

## Conclusões

* O algoritmo testado (Selection Sort em lista) mostra uma complexidade **O(n²)** clara nos resultados. O custo do acesso sequencial na lista (`for j = i->proximo...`) dentro de outro laço (`for i = lista->inicio...`) é o que define este comportamento.
* O tempo de execução se torna **impraticável** para conjuntos de dados acima de 1 milhão de elementos, com estimativas de dias a meses.
* O número de trocas é **linear (O(n))**, sendo um dos pontos fortes do algoritmo, embora o número de comparações o torne lento.
* A ordem dos dados **não afeta o tempo de execução**, apenas o número de trocas.
* A estrutura de lista, devido ao acesso sequencial, torna o Selection Sort ainda **menos eficiente** na prática do que sua versão em vetor, embora a complexidade teórica seja a mesma.
