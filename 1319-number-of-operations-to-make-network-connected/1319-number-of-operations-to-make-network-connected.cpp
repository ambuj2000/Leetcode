class Solution {
public:
    
    void dfs(int src,vector<int>g[],vector<int>&vis){
        vis[src]=1;
        for(auto x:g[src]){
           if(!vis[x]){
               dfs(x,g,vis);
           }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
     int m=connections.size();
    vector<int>g[n];
    if(m<n-1)return -1;
    for(int i=0;i<connections.size();i++){
        g[connections[i][0]].push_back(connections[i][1]);
        g[connections[i][1]].push_back(connections[i][0]);
    }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               cnt++;
               dfs(i,g,vis);
            }
        }
        return cnt-1;
    }
};