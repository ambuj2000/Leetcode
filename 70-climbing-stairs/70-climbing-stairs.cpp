class Solution {
public:
    int climbStairs(int n) {
         int dp[n+1];
        dp[0]=1;//means to go from 0 to 0 there is only 1 way
        for(int i=1;i<=n;i++){
            if(i==1){// if i is 1 
                dp[i]=dp[i-1];
            }
            else {// if i is greater than 1 i.e 2,3,4,5,etc. then it will go to previous steps and access the  already stored value in dp 
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
};