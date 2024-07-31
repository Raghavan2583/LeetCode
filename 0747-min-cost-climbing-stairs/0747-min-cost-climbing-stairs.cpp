class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int len = cost.size()-3;
        
        //iterate the array from right to left and decrease the vector length 3
        
        while(len>-1){
            cost[len] = cost[len] + min(cost[len+1], cost[len+2]);
            len--;
        }
        return min(cost[0], cost[1]);
    }
};