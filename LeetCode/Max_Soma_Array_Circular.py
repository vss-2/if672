# Obs: usando algoritmo de Kadane

def maxSomaCirc(array):
        tam = len(array)

        # Fix para todos os números negativos

        c, l = 0, float('-inf')
        for i in range(len(array)):
                l = max(l, array[i])
                if(array[i] < 0):
                        c = c + 1
        
        if(c == len(array)):
                return l

        # Fim do fix

        def kadane(array):
                tam = len(array)
                max_perm  = 0
                max_atual = 0
                for i in range(tam):
                        max_atual = max_atual + array[i]
                        if(max_atual < 0):
                                max_atual = 0
                        if(max_perm < max_atual):
                                max_perm = max_atual
                return max_perm

        max_k = kadane(array)
        
        # Procurar envolvendo bordas
        max_b = 0

        for i in range(tam):
                max_b     = array[i] + max_b
                array[i]  = -array[i]

        # A soma máxima com os elementos da borda:
        max_b = max_b + kadane(array)

        if(max_b > max_k):
                return max_b
        else:
                return max_k


# maxSomaCirc([4,2,-12])
