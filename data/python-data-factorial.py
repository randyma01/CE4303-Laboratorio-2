import matplotlib.pyplot as plt

priority_levels = [0, -5, -10, -15, -19]
execution_times = [
    0.0008648109978821594,
    0.0008832120001898147,
    0.000845009999466128,
    0.000835109999974956,
    0.0008291110012680292,
]

plt.figure(figsize=(8, 5))
plt.plot(
    priority_levels,
    execution_times,
    marker="o",
    linestyle="-",
    color="green",
    label="Tiempo de Ejecución",
)
plt.xlabel("Nivel de Prioridad [NI]")
plt.ylabel("Tiempo de Ejecucción [s]")
plt.title("Gráfica: Nivel de Prioridad vs. Tiempo de Ejecución")
plt.xticks(priority_levels)
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend()
plt.tight_layout()

plt.show()
