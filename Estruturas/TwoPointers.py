def twoPointers(nums: int, target: int):
    p1 = 0
    p2 = len(nums)-1

    while p1 < p2:
        soma = nums[p1] + nums[p2]

        if soma == target:
            print(nums[p1], nums[p2])
            return True
            # p1 += 1 
            # Comentar linha return True e descomentar acima,
            # caso queira ver todas as somas possíveis
        elif soma < target:
            # A soma ficou abaixo do target, 
            # tem que aumentar
            p1 += 1
        else:
            # A soma ficou acima do target,
            # tem que abaixar
            p2 -= 1
    return False

print(twoPointers([0,1,2,3,4,5], 6))

# Fonte: https://leetcode.com/submissions/detail/689398332/
# Entradas: 
# nums = [-4,-1,0,3,10]
# nums = [-7,-3,2,3,11]
# Saídas: 
# [0,1,9,16,100]
# [4,9,9,49,121]
# Resumo do enunciado: multiplique e ordene os números ao quadrado
# Follow-up: como fazer em tempo melhor que O(n)? Two-pointers

def squaresSortedArray(nums):
    p1 = 0
    p2 = len(nums) - 1
    out = []
    while p1 <= p2:
        if (nums[p1]**2) < (nums[p2]**2):
            out.append(nums[p1]**2)
            p1 += 1
        elif(nums[p1]**2) > (nums[p2]**2):
            out.append(nums[p2]**2)
            p2 -= 1
        else:
            out.append(nums[p1]**2)
            p1 += 1
    return out
    
print(squaresSortedArray(nums = [-4,-1,0,3,10]))
print(squaresSortedArray(nums = [-7,-3,2,3,11]))

# Fonte: https://leetcode.com/problems/rotate-array
# Entradas: 
# nums = [1,2,3,4,5,6,7], k = 3
# nums = [-1,-100,3,99], k = 2
# Saídas:
# [5,6,7,1,2,3,4]
# [3,99,-1,-100]
# Resumo do enunciado: rode os N últimos elementos do array para o começo
# Follow-up: inplace

def rotata(nums, k):
    for i in range(0, k):
        nums.insert(0, nums.pop())

def rotate(nums, k):
    def reverter(first, last):
        while first < last:
            nums[first], nums[last] = nums[last], nums[first]
            first += 1
            last -= 1
    k, n = k % len(nums), len(nums)
    if k:
        reverter(0, n - 1)
        reverter(0, k - 1)
        reverter(k, n - 1)
# Fonte: https://leetcode.com/problems/move-zeroes
# Entradas:
# nums = [0,1,0,3,12]
# nums = [0]
# Saídas:
# [1,3,12,0,0]
# [0]
# Resumo do enunciado: mova para o fim todos os zeros espalhados 
# no array preservando a ordem dos elementos
# Follow-up: inplace

def moveZeroes(nums):
    # nums[:] significa mexer inplace no endereço de memória da variável
    nums[:] = [x for x in nums if x != 0 ]+ [0]*nums.count(0)

def moveZeroes(nums):
    p1 = 0
    for p2 in range(0, len(nums)):
        if nums[p2] != 0 and nums[p1] == 0:
            nums[p1], nums[p2] = nums[p2], nums[p1]
        if nums[p1] != 0:
            p1 += 1
