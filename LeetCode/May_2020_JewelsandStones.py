class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        chars = [0]*100
        otp = 0
        for c in S:
            chars[ord(c)-65] = chars[ord(c)-65] + 1
        for c in J:
            otp = otp + chars[ord(c)-65]
        return otp
