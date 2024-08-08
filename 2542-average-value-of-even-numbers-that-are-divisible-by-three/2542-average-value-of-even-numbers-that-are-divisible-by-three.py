class Solution:
    def averageValue(self, nums: List[int]) -> int:
        s=0
        temp=[]
        for i in range(len(nums)):
            if nums[i]%3==0 and nums[i]%2==0:
                s+=nums[i]
                temp.append(nums[i])
        k=len(temp)
        if k!=0:
            res=s//k
            return res
        return 0


        