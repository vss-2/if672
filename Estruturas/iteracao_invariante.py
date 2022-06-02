# Source: https://leetcode.com/problems/sort-colors/
# Input: nums = [2,0,2,1,1,0]
# Output: [0,0,1,1,2,2]
# Obs: inplace
class Solution:
    def sortColors(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0 # Ponteiro da esquerda
        j = 0 # Ponteiro do meio
        k = len(nums)-1 # Ponteiro da direita
        while j <= k: # Enquanto o ponteiro do meio for menor ou igual ao da direita
            if nums[i] == 0: # Se o número do ponteiro da esquerda for maior que o meio: 
                # ordenamos: trocar o da esquerda com o do meio
                nums[i], nums[j] = nums[j], nums[i]
                # Avançamos o índice de cada, pois estão na sua devida posição
                i += 1
            elif nums[i] == 2: # Se o número do ponteiro da direita for menor que o do meio:
                # ordenamos: trocar o da direita com o do meio
                # retroceder o da direita
                nums[k], nums[j] = nums[j], nums[k]
                k -= 1
                j -= 1
            else:
                # O meio já está na posição correta, avançamos
                j += 1
        return None
