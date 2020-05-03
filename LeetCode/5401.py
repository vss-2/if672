class Solution:
    def kLengthApart(nums, k) -> bool:
        primeiro = 0
        while (True):
            if(nums[primeiro] == 1):
                primeiro = primeiro + 1
                break
            else:
                primeiro = primeiro + 1
                continue
        dist = 0
        while (primeiro < len(nums)):
            if(nums[primeiro] == 0):
                dist = dist + 1
                primeiro = primeiro + 1
                print('Estou na casa', primeiro)
            else:
                primeiro = primeiro + 1
                if(dist >= k):
                    dist = 0
                    print('Passei por 1')
                    continue
                else:
                    print(False)
                    print(primeiro, dist)
                    return False
        return True

Solution.kLengthApart([0,1,0,1], 1)