class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n= arr.size();        
        for(int i=0; i<k; i++){
            pq.push(arr[i] -x);
        }
        
        for(int i=k; i<n; i++){
            if(abs(pq.top()) > abs(arr[i] -x)){
                pq.pop();
                pq.push(arr[i] -x);
            }
        }
               
        vector<int> ans;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            val = val + x;
            ans.push_back(val);
        }
        return ans;
    }
};