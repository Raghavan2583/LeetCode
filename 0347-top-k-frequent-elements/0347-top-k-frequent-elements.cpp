class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto& i:nums) m[i]++;
        vector<vector<int>> freq(nums.size()+1);
        for(auto& it:m) freq[it.second].push_back(it.first);
        for(int i=freq.size()-1;i>=0 && k>0;i--){
            for(int j=0;j<freq[i].size();j++){
                ans.push_back(freq[i][j]);
                k--;
            }
        }
        return ans;
    }
};