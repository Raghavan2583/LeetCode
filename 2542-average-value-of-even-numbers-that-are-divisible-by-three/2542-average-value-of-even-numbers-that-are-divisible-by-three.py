class Solution:
    def averageValue(self, nums: List[int]) -> int:
        s=0
        c=0
        for i in range(len(nums)):
            if nums[i]%3==0 and nums[i]%2==0:
                s+=nums[i]
                c+=1
        
        if c!=0:
            res=s//c
            return res
        return 0


        