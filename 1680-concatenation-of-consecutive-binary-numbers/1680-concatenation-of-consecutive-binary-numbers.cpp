class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
       
        long long int res = 0;
        
        for(int i=1;i<=n; i++){
            unsigned int curr = i;
            int numberOfBits =  log2(curr) + 1; // finding number of bits curr has
            
            res = (res << numberOfBits) % mod; // shifting res to left by `numberOfBits`
            
            res = (res + curr)% mod; // after shifting add curr to res 
            
        }
        
        return res% mod;
    }
};