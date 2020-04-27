# Algoritmo: (Detecção de Ciclos de forma Iterável) Tartarura e Lebre de Floyd
# https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare
# Entrada: [ 1, 2, 3, 4, 4, 5, 6 ]
# Saída: 2, 4, 5

def repetido(array):
        tartaruga = array[0]
        lebre     = array[0]
        while True:
                tartaruga = array[tartaruga]
                lebre  = array[array[lebre]]
                if tartaruga == lebre:
                        break

        num0 = array[0]
        num1 = tartaruga

        while num0 != num1:
                num0 = array[num0]
                num1 = array[num1]
        return num0


print(repetido([1, 2, 3, 4, 4, 5, 6]))