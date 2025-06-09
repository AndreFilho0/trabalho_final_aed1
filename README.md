# trabalho_final_aed1

# Tabela com o que vai ser feito no trabalho de forma geral

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
