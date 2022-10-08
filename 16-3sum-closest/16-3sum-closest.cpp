class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int cur_sum=nums[i]+nums[l]+nums[r];
                if(abs(target-cur_sum)<mini){
                    mini=abs(target-cur_sum);
                    ans=cur_sum;
                }
                if(cur_sum>target)r--;
                else{
                    l++;
                }
                if(target==cur_sum)return ans;
            }
        }
        return ans;
    }
};

