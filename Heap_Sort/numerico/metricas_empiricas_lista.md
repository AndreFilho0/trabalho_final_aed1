# Análise Empírica de Métricas de Ordenação - Lista

Este documento apresenta os resultados empíricos de testes de ordenação em diferentes cenários e tamanhos de dados, utilizando uma estrutura de lista.

## Casos de Teste

### 1. Ordenação de Lista Crescente → Crescente

| Tamanho   | Tempo (s)     | Tempo Humano        | Trocas        | Primeiros Elementos (Ordenados)          |
|-----------|---------------|---------------------|---------------|------------------------------------------|
| 10        | 0.0000100     | Instantâneo         | 30            | 1 2 3 ... 10                             |
| 100       | 0.0001860     | Instantâneo         | 640           | 1 2 3 ... 20                             |
| 1,000     | 0.0126790     | 0.01 segundos       | 9,708         | 1 2 3 ... 20                             |
| 10,000    | 0.4363070     | 0.44 segundos       | 131,956       | 1 2 3 ... 20                             |
| 100,000   | 43.1436400    | 43 segundos         | 1,650,854     | 1 2 3 ... 20                             |
| 1M        | ~4,320        | ~1 hora 12 minutos  | ~20,540,000   | 1 2 3 ... 20                             |
| 10M       | ~432,000      | ~5 dias             | ~256,000,000  | 1 2 3 ... 20                             |
| 100M      | ~43,200,000   | ~1 ano 4 meses      | ~3,300,000,000| 1 2 3 ... 20                             |

**Observações**: 
- Crescimento maior que quadraticamente no tempo conforme aumenta o tamanho
- Número de trocas aumenta quadraticamente

### 2. Ordenação de Lista Aleatória → Crescente

| Tamanho   | Tempo (s)     | Tempo Humano        | Trocas        | Primeiros Elementos (Ordenados)          |
|-----------|---------------|---------------------|---------------|------------------------------------------|
| 10        | 0.0000100     | Instantâneo         | 27            | 5136076 73478952 ... 2091243229          |
| 100       | 0.0001710     | Instantâneo         | 584           | 5136076 23149027 ... 444835065           |
| 1,000     | 0.0075810     | 0.008 segundos      | 9,084         | 5136076 5607661 ... 47472618             |
| 10,000    | 0.4450320     | 0.45 segundos       | 124,194       | 596055 597860 ... 4502919                |
| 100,000   | 39.4547750    | 39 segundos         | 1,575,030     | 9933 57368 ... 617784                    |
| 1M        | ~3,800        | ~1 hora 3 minutos   | ~19,000,000   | [padrão similar aos anteriores]          |
| 10M       | ~390,000      | ~4 dias 12 horas    | ~240,000,000  | [omissos por volume]                     |
| 100M      | ~37,200,000   | ~1 ano 2 meses      | ~3,000,000,000| [omissos por volume]                     |

**Observações**:
- Tempos ligeiramente melhores que na lista já ordenada
- Comportamento similar de crescimento exponencial

### 3. Ordenação Inversa de Lista Crescente → Decrescente

| Tamanho   | Tempo (s)     | Tempo Humano        | Trocas        | Primeiros Elementos (Ordenados)          |
|-----------|---------------|---------------------|---------------|------------------------------------------|
| 10        | 0.0000080     | Instantâneo         | 21            | 10 9 8 ... 1                             |
| 100       | 0.0001150     | Instantâneo         | 516           | 100 99 ... 81                            |
| 1,000     | 0.0079580     | 0.008 segundos      | 8,316         | 1000 999 ... 981                         |
| 10,000    | 0.3399720     | 0.34 segundos       | 116,696       | 10000 9999 ... 9981                      |
| 100,000   | 34.9077050    | 35 segundos         | 1,497,434     | 100000 99999 ... 99981                   |
| 1M        | ~3,050        | ~50 minutos         | ~17,400,000   | 1000000 999999 ... 999981                |
| 10M       | ~306,000      | ~3 dias 13 horas    | ~220,000,000  | 10000000 9999999 ... 9999981             |
| 100M      | ~30,300,000   | ~11 meses 2 semanas | ~2,800,000,000| 100000000 99999999 ... 99999981          |

**Observações**:
- Performance ligeiramente melhor que ordenação crescente
- Menor número de trocas necessárias

## Análise Comparativa

### Crescimento Temporal

![Gráfico de crescimento temporal](crescimento_temporal.png)
*(Inserir gráfico comparando os três cenários)*

### Eficiência por Cenário

1. **Melhor Caso**: Ordenação inversa (Decrescente)
   - Menor número de trocas
   - Tempos ligeiramente menores

2. **Caso Médio**: Dados aleatórios
   - Comportamento intermediário

3. **Pior Caso**: Dados já ordenados (Crescente)
   - Maior número de trocas
   - Tempos mais longos

## Conclusões

- O algoritmo testado mostra complexidade O(n²log(n)) clara nos resultados
- O tempo de execução se torna impraticável para conjuntos acima de 1 milhão de elementos
- O número de trocas é aproximadamente proporcional ao quadrado do tamanho da entrada
- Dados já ordenados representam o pior caso de performance
- A estrutura de lista apresenta limitações significativas para ordenação em grande escala
