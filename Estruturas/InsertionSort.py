# Implementação do Insertion Sort
# Entrada: array (desordenado ou não)
# Saída: array ordenado

def insertionSort(entrada):
	for i in range(1, len(entrada)):
		auxiliar = entrada[i]
		j = i
		while((j > 0) and (entrada[j-1] > auxiliar)):
			entrada[j] = entrada[j-1]
			j = j-1
		entrada[j] = auxiliar
		
entrada = [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
insertionSort(entrada)

print ("O array ordenado: ")	

for x in range (0, len(entrada)):
	print("%d " %entrada[x], end = "")
