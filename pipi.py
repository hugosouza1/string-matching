import matplotlib.pyplot as plt

# Dados fornecidos
tamanhos = [1000, 5000, 10000, 15000, 20000, 25000]

forca_bruta = [992188, 5042586, 10111054, 15110042, 20239410, 25287312]
kmp = [953802, 4822506, 9661098, 14429302, 19326588, 24172294]
bmh = [424078, 2115561, 4231365, 6326609, 8478298, 10579141]
shift_and = [651902, 3291163, 6589178, 9838934, 13184988, 16477253]

# Criando o gráfico
plt.figure(figsize=(10, 6))

# Alterando a cor do fundo
ax = plt.gca()  # Obtém o objeto dos eixos atuais
ax.set_facecolor('lightgray')  # Define a cor do fundo como lightgray

# Plotando as linhas
plt.plot(tamanhos, forca_bruta, marker='o', label='Força Bruta', color='blue')
plt.plot(tamanhos, kmp, marker='o', label='KMP', color='green')
plt.plot(tamanhos, bmh, marker='o', label='BMH', color='red')
plt.plot(tamanhos, shift_and, marker='o', label='ShiftAnd', color='purple')

# Adicionando título e labels
plt.title('Comparação de Algoritmos de Casamento de Cadeia de Caracteres', fontsize=16)
plt.xlabel('Tamanho da Entrada', fontsize=14)
plt.ylabel('Número de Comparações', fontsize=14)

# Adicionando legenda
plt.legend(fontsize=12)

# Habilitando grid
plt.grid(True, linestyle='--', alpha=0.7)

# Mostrando o gráfico
plt.show()