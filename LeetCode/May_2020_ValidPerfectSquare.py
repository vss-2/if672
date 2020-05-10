class Solution:
    def buscabinaria(l, esq, dire, num):
        if (dire >= esq):
            meio = esq + (dire - esq) // 2
            #print(meio)
            if (meio*meio == num):
                return True
            elif (meio*meio > num):
                return Solution.buscabinaria(l, esq, meio-1, num)
            else:
                return Solution.buscabinaria(l, meio+1, dire, num)
        else:
            return False
    def isPerfectSquare(self, num: int) -> bool:
        l = []
        if(num == 1): 
            return True
        return Solution.buscabinaria(l, 0, num, num)