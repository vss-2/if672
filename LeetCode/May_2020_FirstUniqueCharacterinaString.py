class Solution:
    def firstUniqChar(self, s: str) -> int:
        arr = [0] * 30
        i = 0
        for l in s:
            if arr[ord(l)-97] == 0 :
                arr[ord(l)-97] = 1
            else:
                arr[ord(l)-97] = 1 + arr[ord(l)-97]

        i = 0
        menor = len(s) + 2
        for k in arr:
            if(k != 0):
                if(arr[i] == 1):
                    if(menor > s.find(chr(i+97))):
                        menor = s.find(chr(i+97))
            i = i + 1
        if (menor == len(s) + 2):
            return -1
        else:
            return menor
