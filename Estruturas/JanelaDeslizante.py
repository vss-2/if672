# https://leetcode.com/problems/permutation-in-string/discuss/638531/Java-or-C%2B%2B-or-Python3-or-Detailed-explanation-or-O(N)-time

# Fonte: https://leetcode.com/problems/permutation-in-string/
# Resumo do enunciado:
# A string s1 é permutação de alguma substring de s2?

def checkInclusion(s1: str, s2: str) -> bool:
    a, b, pos = [0]*26, [0]*26, []
    if(len(s1) == 0):
        return pos

	# Converte todos chars para ints de s1
    for i in s1:
        a[ord(i)-ord('a')] += 1

    ini = 0
    fim = len(s1)
    tf = True

	# Converte todos chars para ints de s2
    for i in s2[ini:fim]:
        b[ord(i)-ord('a')] += 1

    while(fim < len(s2)):
        # Converte em int e compara
        for i in range(0, 26):
            if(a[i] != b[i]):
                tf = False
        if tf:
            return True

        # Avançar janela
        b[ord(s2[ini])-ord('a')] -= 1  # tira da janela letra de trás
        b[ord(s2[fim])-ord('a')] += 1  # bota na janela letra da frente
        fim += 1
        ini += 1
        tf = True

	# Verifica se vetor a != b,
	# pois ao fim da execução a janela deve ser igual a s1
    for i in range(0, 26):
        if(a[i] != b[i]):
            tf = False
    if tf:
        return True
    return False


print(checkInclusion(s1="ab", s2="eidbaooo"), ': expected True')
print(checkInclusion(s1="ab", s2="eidboaoo"), ': expected False')

# Fonte: https://leetcode.com/problems/find-all-anagrams-in-a-string/
# Resumo do enunciado:
# Retorne todos os índices os quais existe um anagrama na string s

def findAnagrams(self, s: str, p: str) -> int:
    a, b, pos = [0]*26, [0]*26, []
    bkp = [0]*26
    if(len(p) == 0):
        return pos

    for i in p:
        a[ord(i)-ord('a')] += 1

    ini = 0
    fim = len(p)
    tf = True

    for i in s[ini:fim]:
        b[ord(i)-ord('a')] += 1

    while(fim < len(s)):
        # Converte e compara
        for i in range(0, 26):
            if(a[i] != b[i]):
                tf = False
        if tf:
			# Salva posição inicial
            pos.append(ini)

        # Avançar janela
        b[ord(s[ini])-ord('a')] -= 1
        b[ord(s[fim])-ord('a')] += 1
        fim += 1
        ini += 1

        tf = True
    for i in range(0, 26):
        if(a[i] != b[i]):
            tf = False
    if tf:
        pos.append(ini)
    return pos

print(findAnagrams(s = "cbaebabacd", p = "abc"), ': expected [0,6]')
print(findAnagrams(s = "abab", p = "ab"), ': expected [0,1,2]')
