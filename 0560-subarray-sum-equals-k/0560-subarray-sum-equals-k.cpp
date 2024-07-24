class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sz = nums.size();
        
        unordered_map<int, int> mp; //cumulative sum, occurance
        mp[0] = 1;
        int sum = 0;
        for(int i = 0; i<sz; i++){
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end())
                count += mp[sum-k];
            mp[sum]++;
        }       
        return count;
    }
};