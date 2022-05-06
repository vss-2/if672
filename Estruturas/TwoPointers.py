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


# Fonte: https://leetcode.com/problems/remove-nth-node-from-end-of-list
# Entrada:
# [1,2,3,4,5]
# 2
# Saída:
# [1,2,3,5]
# Resumo do enunciado:
# Dado uma lista encadeada, delete n-ésimo último item
# Definition for singly-linked list. Classe fornecida pela questão
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def removeNthFromEnd(head: ListNode, n: int) -> ListNode:
    p1 = head
    p2 = head
    
    # A sacada de usar o two pointers é porque um vai até o 
    # fim mais rápido e sinaliza ao outro para parar e remover o elemento

    # Avança 2o ponteiro para frente,
    # garantido que tá nos limites
    for move in range(n):
        p2 = p2.next
    
    # Caso específico de p2 ser o último
    if p2.next == None:
        return head.next
    
    # Caso padrão te que percorrer todos
    while p2.next != None:
        p1 = p1.next
        p2 = p2.next
    
    # Dado que o p2 segue avançando a uma
    # distância "n", você só precisa deletar
    # quando o p2 chegar ao fim
    p1.next = p1.next.next
    
    return head

# Fonte: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/
# Entrada: "abbaca"
# Saída: "ca"
# Resumo do enunciado: agrupe e remova os pares de caracteres
# Follow-up: e se eu quiser remover apenas grupos de k caracteres ocupados?
# Fonte follow-up: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
# Obs: possível fazer essa e o follow-up com pilha
def removeDuplicates(s: str) -> str:
    p1, p2 = 0, 0
    
    # É uma cópia do input, mas em array/lista, não string
    tf = list(s)

    for _ in range(0, len(s)):
        # Avança os ponteiros para o mesmos caractere
        tf[p1] = tf[p2]

        # Se um ponteiro não for o primeiro caractere
        # e se o caractere anterior foi o igual ao atual
        # então significa que o primeiro ponteiro volta 
        # esses 2 caracteres repetidos ("pula pra trás"). 
        # Dessa forma você vai estar gravando no começo do array, em espaço O(N),
        # os caracteres não repetidos, depois é só cortar o vetor ao último caractere alterado do começo
        if p1 > 0 and tf[p1 - 1] == tf[p1]:
            p1 -= 2
        
        # No follow-up, a condicional acima seria:
        # tf seria um array de contar repetidos
        # if p1 > 0 and s[p1 - 1] == s[p2]:
        #   tf[p1 - 1] += 1
        # else:
        #   tf[p1 - 1] = 1
        # if tf[p1] == k:
        #   p1 -= k

        p1 += 1
        p2 += 1
    
    return ''.join(tf[0:p1])