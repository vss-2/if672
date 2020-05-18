# Adaptacao da questao do dia imediatamente anterior
# https://github.com/vss-2/if672/blob/master/LeetCode/May_2020_Find_All_Anagrams_in_a_String.py
class Solution:
        def checkInclusion(self, s1: str, s2: str) -> bool:
                a, b, pos = [0]*26, [0]*26, []
                bkp = [0]*26
                if(len(s1) == 0):
                        return pos

                for i in s1:
                        a[ord(i)-ord('a')] += 1
                        
                ini = 0
                fim = len(s1)
                tf = True

                for i in s2[ini:fim]:
                        b[ord(i)-ord('a')] += 1
                
                while(fim < len(s2)):
                        for i in range(0, 26):
                                if(a[i] != b[i]):
                                        tf = False
                        if tf:
                                return True
                        b[ord(s2[ini])-ord('a')] -= 1
                        b[ord(s2[fim])-ord('a')] += 1
                        fim += 1
                        ini += 1
                        
                        tf = True
                for i in range(0, 26):
                        if(a[i] != b[i]):
                                tf = False
                if tf:
                        return True
                return False