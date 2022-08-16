class Solution {
public:
    int firstUniqChar(string s) {
   unordered_map<char,int>mp;
        int res=-1;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for( int i=0;i<s.length();i++){
             if(mp[s[i]]==1){
                 res=i;
                 break;
             }
        }
        return res;
    }
};