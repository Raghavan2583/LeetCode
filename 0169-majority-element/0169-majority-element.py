class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ele=0
        c=0
        for i in range(len(nums)):
            if c==0:
                c=1
                ele=nums[i]
            elif ele==nums[i]:
                c+=1
            else:
                c-=1
        c1=0
        for i in range(len(nums)):
            if ele == nums[i]:
                c1+=1
        if c1>(len(nums)/2):
            return ele
        return 0