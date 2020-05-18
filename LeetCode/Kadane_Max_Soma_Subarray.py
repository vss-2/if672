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
