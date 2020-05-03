from random import randint
class Solution:       
    def maxDiff(num: int) -> int:
        num = 555
        stringX = str(num)
        stringY = str(num)

        def gerarNumero(valor, subs):
            print('Valor:', valor)
            i = 0
            while(True):
                if(valor[i] != 0):
                    break
                else:
                    i = i+1
            x = str(valor[i])
            print('X:', x, '\n')

            y = randint(1,9)
            y = str(y)
            print('Y:', y, '\n')

            output = ''
            for k in range(0, len(str(valor))):
                if(valor[k] == x):
                    output = output + str(y)
                else:
                    output = output + str(valor[k])
            print(output)
            return output
        
        a = int(gerarNumero(stringX, stringY))
        b = int(gerarNumero(stringX, stringY))

        print(max(a-b, b-a))
        return max(a-b, b-a)

Solution.maxDiff(555)