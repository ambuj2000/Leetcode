class Solution {
public:
vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int n=nums.size();
    vector<int> ans;
    int sum=0;
    for(int j=0;j<n;j++){
        if(nums[j]%2==0)
             sum+=nums[j];
    }
    for(int i=0;i<n;i++){
        int ind=queries[i][1], val=queries[i][0];
        if(nums[ind]%2==0)
             sum-=nums[ind];
        nums[ind]=nums[ind]+val;
        if(nums[ind]%2==0)
             sum+=nums[ind];
        ans.push_back(sum);
    }
    return ans;
}
};