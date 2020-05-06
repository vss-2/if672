class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()

        c, c1 = 0, 0
        n, n1 = 0, 0
        c = nums[0]
        for i in nums:
            if(i == c):
                n = n + 1
            else:
                if(n > n1):
                    c1,n1 = c,n

                c = i
                n = 1

        if(n > n1):
            c1,n1 = c,n

        return c1
