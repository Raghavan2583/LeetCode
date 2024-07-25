class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans=set()
        nums.sort()
        N=len(nums)
        for i in range(N):
            if(i!=0 and nums[i]==nums[i-1]):
                continue
            for j in range(i+1,N):
                if j< i+1 and nums[j]!=nums[j-1]:
                    continue
                f=j+1
                k=N-1
                while f<k:
                    sums= nums[i]+nums[j]+nums[f]+nums[k]
                    if sums<target:
    
                        f+=1
                    elif sums > target:
                        k-=1
                    
                    else:
                        temp=(nums[i],nums[j],nums[f],nums[k])
                        ans. add(temp)
            
                        f+=1
                        k-=1
                # while(j<k and nums[j] == nums[j-1]):
                #     j+=1
                # while(j<k and nums[k-1] == nums[k]):
                #     k-=1
        return ans