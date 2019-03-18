# Busca binária implementada de forma recursiva
# Entrada: array (espera-se desordenado)
# Saída: array (ordenado)

def buscaBinaria (entrada, esq, dir, busca):
    if dir >= esq:
        meio = esq + (dir - esq)/2
        if entrada[meio] == busca:
            return meio
        elif entrada[meio] > busca:
            return buscaBinaria(entrada, esq, meio-1, busca)
        else:
            return buscaBinaria(entrada, meio+1, dir, busca)
    else:
        # Elemento não está no array
        return -1

entrada = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
busca = 7

resposta = buscaBinaria (entrada, 0, len(entrada)-1, busca)

if resposta != -1:
    print "O valor buscado está no índice: % d" % result
else:
    print "O valor buscado não está no array!"
