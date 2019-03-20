# Implementação do Merge Sort 
# Entrada: array (desordenado ou não)
# Saída: array ordenado
# Obs o Merge Sort é preciso,
# havendo valores repetidos, ele preserva
# a ordem que tais valores estavam, além 
# disso, esta versão iterativa é mais rápida
# que a recursiva

def mergeSort(entrada):
	if (len(entrada) > 1):
		meio = int(len(entrada)/2)
		
		ladoEsq = entrada[:meio]
		ladoDir = entrada[meio:]
		
		mergeSort(ladoEsq)
		mergeSort(ladoDir)
		
		i = j = k = 0
		
		while (i < len(ladoEsq) and j < len(ladoDir)):
			if (ladoEsq[i] < ladoDir[j]):
				entrada[k] = ladoEsq [i]
				i = i+1
			else:
				entrada[k] = ladoDir[j]
				j = j+1
			k = k+1
			
		while (i < len(ladoEsq)):
			entrada[k] = ladoEsq[i]
			i = i+1
			k = k+1
		while (j < len(ladoDir)):
			entrada[k] = ladoDir[j]
			j = j+1
			k = k+1


entrada = [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
mergeSort(entrada)

print ("O array ordenado: ")	

for x in range (0, len(entrada)):
	print("%d " %entrada[x], end = "")
