/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode*sortedArrayToBST(vector<int>nums,int left,int right){
        if(right<=left)return NULL;
        int mid=(right+left)>>1;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(nums,left,mid);
        root->right=sortedArrayToBST(nums,mid+1,right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size());
    }
};