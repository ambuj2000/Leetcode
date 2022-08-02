class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //using binary search
        int n=matrix.size();
        if(matrix.empty())return 0;
        int l=matrix[0][0];
        int r=matrix[n-1][n-1];
        while(l<r){
         int cnt=0;
         int mid=l+(r-l)/2;
         for(int i=0;i<n;i++){
         cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
            if(cnt<k)l=mid+1;
            else r=mid;
        }
        return l; 
    }
    
};