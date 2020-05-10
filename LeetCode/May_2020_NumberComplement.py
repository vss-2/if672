class Solution:
        def findComplement(self, num: int) -> int:
                return int(''.join(map(lambda x: '0' if x == '1' else '1', bin(num)[2:])),2)

#############################################################################################

class Solution:
    def findComplement(self, num: int) -> int:
        b = bin(num)[2:]
        c = ''
        for digit in b:
            if(digit == '0'):
                c = c + '1'
            else:
                c = c + '0'
        return int(c, 2)                
