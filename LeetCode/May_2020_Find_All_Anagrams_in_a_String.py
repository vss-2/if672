class Solution:
        def findAnagrams(self, s: str, p: str) -> List[int]:
                a, b, pos = [0]*26, [0]*26, []
                bkp = [0]*26
                if(len(p) == 0):
                        return pos

                for i in p:
                        # Preenche quantidades do anagrama
                        a[ord(i)-ord('a')] += 1
                        
                ini = 0
                fim = len(p)
                tf = True

                for i in s[ini:fim]:
                        b[ord(i)-ord('a')] += 1
                
                while(fim < len(s)):
                        # Compara conjunto: janela e anagrama
                        for i in range(0, 26):
                                if(a[i] != b[i]):
                                        tf = False
                        if tf:
                                return True
                                pos.append(ini)
                        
                        # Avançar janela
                        b[ord(s[ini])-ord('a')] -= 1
                        b[ord(s[fim])-ord('a')] += 1
                        fim += 1
                        ini += 1
                        
                        tf = True
                # Verificacao do ultimo (fix)
                for i in range(0, 26):
                        if(a[i] != b[i]):
                                tf = False
                if tf:
                        pos.append(ini)
                return pos
