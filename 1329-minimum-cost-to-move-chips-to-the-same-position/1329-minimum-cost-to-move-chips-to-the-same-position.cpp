class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) 
    {
        int odd=0,even=0;
        for(int i=0;i<pos.size();i++)
        {
            if(pos[i]%2==0)
                even++;
            else
                odd++;
        }
        return min(even,odd); //all even pos collected with 0 cost same all odd
                              // then collect odd even at same position
        
    }
};
//if you find the solution useful plz upvote.