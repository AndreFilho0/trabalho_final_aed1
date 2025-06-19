import matplotlib.pyplot as plt

# Dados
casos = [
    "Original → Crescente",
    "Original → Decrescente",
    "Crescente → Decrescente"
]

tempos = [0.8976200, 0.8764140, 0.8428970]
trocas = [19048277, 19048448, 18333401]

# Gráfico de Tempo
plt.figure(figsize=(8, 5))
plt.bar(casos, tempos, color='skyblue')
plt.ylabel("Tempo (segundos)")
plt.title("Heap Sort (1M elementos) - Tempo de Execução")
plt.xticks(rotation=20)
plt.tight_layout()
plt.savefig("selection_sort_textual_1M_tempo.png")
plt.close()

# Gráfico de Trocas
plt.figure(figsize=(8, 5))
plt.bar(casos, trocas, color='salmon')
plt.ylabel("Número de Trocas")
plt.title("Heap Sort (1M elementos) - Número de Trocas")
plt.xticks(rotation=20)
plt.tight_layout()
plt.savefig("selection_sort_textual_1M_trocas.png")
plt.close()

print("Gráficos gerados com sucesso!")

