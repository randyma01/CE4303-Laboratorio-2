import matplotlib.pyplot as plt

number_threads = [1, 2, 3, 4, 5]
execution_times = [0.02664, 0.003222, 0.013905, 0.013609, 0.007060]

plt.figure(figsize=(8, 5))
plt.plot(
    number_threads,
    execution_times,
    marker="o",
    linestyle="-",
    color="blue",
    label="Tiempo de Ejecución",
)
plt.xlabel("Cantidad de Hilos")
plt.ylabel("Tiempo de Ejecucción [s]")
plt.title("Gráfica: Cantidad de Hilos vs. Tiempo de Ejecución")
plt.xticks(number_threads)
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend()
plt.tight_layout()

plt.show()
