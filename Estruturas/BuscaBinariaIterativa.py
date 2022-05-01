from random import randint

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

# Fonte: https://leetcode.com/problems/search-insert-position/
# Entradas:
# nums = [1,3,5,6], target = 5
# nums = [1,3,5,6], target = 2
# nums = [1,3,5,6], target = 7
# Saídas:
# 2
# 1
# 4

# Resumo do enunciado: 
# Esse elemento está na lista? Senão, onde inserí-lo, se sim, em qual posição?

def searchInsert(nums: int, target: int) -> int:
    left  = 0
    right = len(nums)
    print(nums, target)
    while left <= right:
        mid = int(((left+right)/2))
        if target < nums[mid]:
            right = mid
        elif target > nums[mid]:
            left  = mid
        else:
            return mid
        if nums[mid-1] == nums[left]:
            if target <= nums[left]:
                return left
            return left+1
        if nums[mid] == nums[right-1]:
            return right

print(searchInsert(nums = [1,3,5,6], target = 5))
print(searchInsert(nums = [1,3,5,6], target = 2))
print(searchInsert(nums = [1,3,5,6], target = 7))

# Fonte: https://leetcode.com/problems/first-bad-version/
# Entradas: 
# n = 5, bad = 4
# n = 1, bad = 1
# Saídas:
# 4
# 1
# Resumo do enunciado: 
# Dada uma função isBadVersion, a qual retorna verdadeiro ou falso
# caso o número fornecido seja uma versão defeituosa, ache a primeira ocorrência 
# (depois da primeira todas serão defeituosas)
# da versão defeituosa com o mínimo de requisições a essa função.

r = randint(0, 2147483648-1)
def isBadVersion(n) -> int:
    if n < r:
        return False
    return True

def firstBadVersion(n: int) -> int:
    output = set()
    minV = 2147483648 - 1
    left = 0
    right = 2147483648 - 1
    while left <= right:
        mid = int(((left+right)/2))
        if mid in output:
            return mid+1
        output.add(mid)
        tf = isBadVersion(mid)
        if tf:
            right = mid
            minV = min(right, minV)
        else:
            left = mid
            if tf:
                minV = min(left, minV)