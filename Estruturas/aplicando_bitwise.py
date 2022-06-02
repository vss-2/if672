# Source: https://leetcode.com/problems/divide-two-integers/
# Input: dividend = 10, divisor = 3
# Output: 3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        quo = 31
        cient = 0
        neg = False
        if dividend < 0 and not divisor < 0:
            neg = True
        elif not dividend < 0 and divisor < 0:
            neg = True
        dividend = abs(dividend)
        divisor = abs(divisor)
        while(quo > -1):
            # print(dividend, quo, cient)
            if((divisor << quo) <= dividend):
                # Utilizando a divisão binária para agilizar a subtração
                dividend -= divisor << quo
                cient += 2**quo
            # Atualizar contador
            quo -= 1
        #print(dividend, quo, cient)
        if cient > (2**31)-1 and not neg: return (2**31)-1
        return -cient if neg else cient

# https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
# Input: s = "00110110", k = 2
# Output = True
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        # Adicionando combinações
        binary_codes = set() 
        
        # Montando string
        chars = []
        for c in s:
            chars.append(c)
            if len(chars) == k:
                # Adiciono sempre que o tamanho da string for igual ao k
                binary_codes.add(''.join(chars))
                
                # Removo o primeiro caractere para garantir todas as combinações
                del chars[0]
            # Verificando se o tamanho é igual a 2**k
            if len(binary_codes) == 1 << k:
                return True
        return len(binary_codes) == 1 << k
