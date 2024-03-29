class Solution {
public:
    string pushDominoes(string str) {
        int n = str.size();
        vector<int> dp(n+1, 0);
        
        bool pushed = false;
        for(int i=n-1; i>=0; i--){
            if(str[i] == 'L'){
                dp[i] = 1;
                pushed = true;
            }
            else if(str[i] == '.' && pushed){
                dp[i] = dp[i+1]+1;
            }
            else if(str[i] == 'R'){
                pushed = false;
            }
        }
        
        pushed = false;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(str[i] == 'R'){
                cnt = -1;
                pushed = true;
            }
            else if(str[i] == '.' && pushed){
                cnt--;
            }
            else if(str[i] == 'L'){
                cnt = 0;
                pushed = false;
            }

            if(dp[i] == 0){
                dp[i] = cnt;
            }
            else if(cnt<0 && dp[i]+cnt >= 0){
                dp[i] = -(cnt+dp[i]);
                if(dp[i] == 0){ 
                    cnt = 0;
                    pushed = false;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(dp[i] == 0) str[i] = '.';
            else if(dp[i] < 0) str[i] = 'R';
            else str[i] = 'L';
        }
        
        return str;
    }
};