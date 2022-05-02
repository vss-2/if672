# Questões que é necessário perceber
# um padrão para virar a chave

# Fonte: https://leetcode.com/submissions/detail/691004096/
# Entrada: s = "abbca"
# Saída: 28
# Resumo do enunciado:
# Para cada subcadeia de caracteres existente 
# (com repetição) indique a soma de caracteres 
# únicos de cada subcadeia. 
# Ex: 'abc' = 'a', 'b', 'c', 'ab', 'bc' = 7
def appealSum(self, s: str) -> int:
    soma  = [1]
    ant   = 1
    atual = 0
    
    d = dict({s[0]: 0})
    
    # A lógica da questão é perceber um padrão:
    # itere adicionando caractere a caractere, este é o índice
    # assim que você vê uma letra nova: a pontuação dela é 1+ a pontuação da subcadeia anterior
    # assim que você vê uma letra repetida: subtraia a aparição atual - a última aparição dela
    # Discussão: https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996300/Python3-or-O(N)-O(1)-or-detail-for-beginners
    # Essa abordagem não perde tempo criando subcadeias, ela fragmenta a entrada e faz o cálculo mais rápido por isso

    for r in range(1, len(s)):
        if s[r] in d:
            atual = ant + (r-d[s[r]])
        else:
            atual = ant + (r + 1)
        soma.append(atual)
        ant = atual
        d[s[r]] = r
    # print(soma)
    return sum(soma)
