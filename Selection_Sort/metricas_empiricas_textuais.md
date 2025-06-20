# Análise de Performance: Selection Sort com Dados Textuais

Este documento apresenta a análise de performance e as métricas empíricas (estimadas) para o algoritmo **Selection Sort** aplicado a um conjunto de dados textuais. Os testes consideram a ordenação de **1.000.000 de nomes aleatórios** utilizando implementações baseadas em vetor e em lista duplamente encadeada.

## Complexidade e Estimativa de Tempo

O Selection Sort possui uma complexidade de tempo de **O(n²)** para comparações e **O(n)** para trocas. Para um conjunto de dados com n = 1.000.000, o número de comparações é da ordem de 500 trilhões, tornando a execução real impraticável.

Os tempos de execução apresentados abaixo são **estimativas teóricas** baseadas nesses cálculos para demonstrar a inviabilidade do algoritmo em larga escala, em contraste com algoritmos mais eficientes como o Heap Sort (O(n log n)).

---

## 1. Implementação com Vetor (Array)

A implementação em vetor se beneficia do acesso contíguo à memória, o que melhora a localidade de cache. No entanto, isso não é suficiente para superar a complexidade quadrática.

| Caso de Teste             | Direção da Ordenação | Tempo de Execução (Estimado) | Nro. de Trocas (Máximo) | Observações                                                                        |
| ------------------------- | -------------------- | ---------------------------- | ----------------------- | ---------------------------------------------------------------------------------- |
| Original → Crescente      | CRESCENTE            | **~7 horas**                 | 999.999                 | Ordenação padrão de dados aleatórios. O tempo é dominado pelas comparações.      |
| Original → Decrescente    | DECRESCENTE          | **~7 horas**                 | 999.999                 | Performance similar ao caso crescente, pois o número de comparações não muda.     |
| Crescente → Decrescente   | DECRESCENTE          | **~7 horas**                 | 999.999                 | Pior caso para trocas. Cada elemento precisa ser movido.                            |

---

## 2. Implementação com Lista Duplamente Encadeada

A versão com lista duplamente encadeada sofre uma penalidade de performance devido ao acesso sequencial via ponteiros (ponteiro->proximo), que impede a otimização de cache pelo processador.

| Caso de Teste             | Direção da Ordenação | Tempo de Execução (Estimado) | Nro. de Trocas (Máximo) | Observações                                                                        |
| ------------------------- | -------------------- | ---------------------------- | ----------------------- | ---------------------------------------------------------------------------------- |
| Original → Crescente      | CRESCENTE            | **~8.5 horas**               | 999.999                 | Mais lento que o vetor devido ao custo do acesso sequencial por ponteiros.          |
| Original → Decrescente    | DECRESCENTE          | **~8.5 horas**               | 999.999                 | O número de comparações e a lógica de acesso permanecem os mesmos.                 |
| Crescente → Decrescente   | DECRESCENTE          | **~8.5 horas**               | 999.999                 | A complexidade quadrática do acesso aos nós domina qualquer outro fator.             |

---

## Conclusões

1.  **Inviabilidade Prática:** O Selection Sort é **completamente inviável** para ordenar grandes volumes de dados (1.000.000 de elementos), com tempos de execução estimados em várias horas.

2.  **Vetor vs. Lista:** A implementação com **vetor é teoricamente mais rápida** que a com lista duplamente encadeada, graças ao acesso eficiente à memória e melhor aproveitamento do cache da CPU.

3.  **Gargalo:** O gargalo do algoritmo é o **número massivo de comparações (O(n²))**. A vantagem de ter poucas trocas (O(n)) é irrelevante diante do custo das comparações.

4.  **Comparativo:** Um algoritmo de complexidade **O(n log n)**, como o Heap Sort, executaria a mesma tarefa em **poucos segundos**, evidenciando a importância crítica da escolha do algoritmo correto para a escala do problema.