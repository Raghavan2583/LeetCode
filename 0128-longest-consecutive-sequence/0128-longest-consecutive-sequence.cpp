class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0)
        {
            return 0; 
        }
        if(n==1)
        {
            return 1;
        }
        sort(a.begin(),a.end());
        int maxi=0;
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]==a[i]+1)
            {
                count++;
            }
            else if(a[i+1]==a[i]){
                count=count;
            }
            else{
                count=0;
            }
            maxi=max(maxi,count);
        }
        
        return maxi+1;
    }
};