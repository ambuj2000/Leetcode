class Solution {
public:
     int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int count=0;
        for(string word:words)
        {
           mp[word]++;
        }
        unordered_set<string> s;
        bool flag=false;
        for(string word:words)
        {
            if(s.count(word)==0)
            {
                string t="";
                t+=word[1];
                t+=word[0];
                if(t==word)
                    count+=mp[t]/2;
                else count+=min(mp[t],mp[word]);
                s.insert(t);
                s.insert(word);
                if(mp[t]%2==1 && t[0]==t[1])
                    flag=true;
            }
        }
        count=count*4;
        if(flag) count+=2;
        return count;
    }
};