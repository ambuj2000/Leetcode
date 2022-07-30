class Solution {
public:
vector<string> ans;

void fun(int idx, string& s, unordered_set<string>& word, string sf){
    if(idx == s.length()){
        
        ans.push_back(sf.substr(1));
        
        return;
        
    }
    
    
    for(int i = idx; i < s.length(); i++){
        
        string curWord = s.substr(idx , i-idx+1);
        
        if(word.count( curWord ))
            fun(i+1, s, word , sf + " " + curWord);
        
    }
    
    return;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    
    unordered_set<string> word(wordDict.begin(), wordDict.end());
    
    fun(0, s, word, {});
    
    return ans;
}
};