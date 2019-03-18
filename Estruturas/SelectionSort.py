# Implementação do Selection Sort
# Entrada: array (desordenado ou não)
# Saída: array ordenado

def selectionSort(entrada, tamanho):
	i = j = menor = auxiliar = 0
	for i in range (0,tamanho-1):
		menor = i
		for j in range (i+1,tamanho):
			if(entrada[j] < entrada[menor]):
				menor = j
			j = j+1
		if(entrada[i] != entrada[menor]):
			# Swap
			auxiliar = entrada[i]
			entrada[i] = entrada[menor]
			entrada[menor] = auxiliar
	i = i+1

entrada = [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]

selectionSort(entrada, len(entrada))

print ("O array ordenado: ")	

for x in range (0, len(entrada)):
	print("%d " %entrada[x], end = "")
