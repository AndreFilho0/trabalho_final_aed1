import matplotlib.pyplot as plt
import numpy as np

def gerar_graficos(nome_algoritmo, nome_caso, tamanhos, tempos, trocas):
    # Convertendo tamanhos para valores numéricos
    tamanhos_legenda = tamanhos
    tamanhos_numericos = []
    for t in tamanhos:
        if 'M' in t:
            tamanhos_numericos.append(int(t.replace('M', '')) * 1_000_000)
        elif 'K' in t:
            tamanhos_numericos.append(int(t.replace('K', '')) * 1_000)
        else:
            tamanhos_numericos.append(int(t.replace(',', '')))

    # Aplicar raiz cúbica apenas para visualização
    tamanhos_plot = [np.cbrt(x) for x in tamanhos_numericos]

    # Gráfico de Tempo
    plt.figure(figsize=(10, 5))
    plt.plot(tamanhos_plot, tempos, marker='o', color='blue')
    plt.xticks(tamanhos_plot, tamanhos_legenda, rotation=45)
    plt.xlabel("Tamanho dos dados (ajustado)")
    plt.ylabel("Tempo (segundos)")
    plt.title(f"{nome_algoritmo} - {nome_caso} (Tempo)")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"{nome_algoritmo}_{nome_caso}_tempo.png".replace(" ", "_"))
    plt.close()

   

    print(f"✅ Gráficos ajustados gerados para: {nome_algoritmo} - {nome_caso}")

# Exemplo de uso:
nome_alg = "Heap Sort"
caso1 = "numerico Crescente → Decrescente"

tamanhos = ["10", "100", "1,000", "10,000", "100,000", "1M", "10M", "100M"]
tempos = [0.0000030, 0.0000140, 0.0001750, 0.0026070, 0.0319030, 0.3681550, 3.9698390, 40.9332120]
trocas = [30, 640, 9708, 131956, 1650854, 19787792, 231881708, 2652454802]

gerar_graficos(nome_alg, caso1, tamanhos, tempos, trocas)
