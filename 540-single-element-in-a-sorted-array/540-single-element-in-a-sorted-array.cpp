class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
       int ele=0;
        for(int i=0;i<n;i++){
            ele=ele^nums[i];
        }
        return ele;
    }
};