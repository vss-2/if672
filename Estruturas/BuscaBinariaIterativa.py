# Busca binária implementada de forma iterativa
# Entrada: array (espera-se ordenado)
# Saída: índice do valor buscado (se estiver presente no array)

def buscaBinaria (entrada, tamanho, busca):
    esq = 0
    dir = tamanho - 1
    while esq <= dir:
        meio = int((esq + dir)/2) 
        # int serve como floor
        
        if entrada[meio] < busca:
            esq = meio + 1
        elif entrada[meio] > busca:
            dir = meio - 1
        else:
            return meio
    
    # Elemento não está no array
    return -1 

entrada = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
busca = 7

resposta = buscaBinaria (entrada, 0, len(entrada)-1, busca)

if resposta != -1:
    print ("O valor buscado está no índice: % d" % resposta)
else:
    print ("O valor buscado não está no array!")
