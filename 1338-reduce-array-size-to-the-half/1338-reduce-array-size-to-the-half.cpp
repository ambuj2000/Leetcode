class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int>mp;
        for(auto x:arr){
            mp[x]++;
        }
        multimap<int,int,greater<int>>mm;
        for(auto it:mp){
            mm.insert({it.second,it.first});
        }
        int n=arr.size();
        int sum=n;
        int count=0;
        for(auto it=mm.begin();it!=mm.end();it++){
                sum-=it->first;
            count++;
            if(sum<=n/2){
                return count;
            }
        }
        return count;
    }
};