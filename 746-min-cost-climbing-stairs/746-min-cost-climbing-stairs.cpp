class Solution {
public:
    int utility(vector<int>&cost, int index, vector<int>&dp)
    {
        if(index>=cost.size()) 
            return 0;
        
        if(dp[index] != -1) 
            return dp[index];
        
        int ostep = cost[index]+ utility(cost, index+1, dp);    //climbing 1 step
        int tstep = cost[index]+ utility(cost, index+2, dp);    //climbing 2 strep
            
        return dp[index] = min(ostep, tstep);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        
        //explore both possibility of starting from index 0 and index 1
        return min (utility(cost, 0, dp), utility(cost, 1, dp)); 
    }
};