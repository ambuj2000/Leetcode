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
public:
void solve(TreeNode* root,  vector<vector<int>> & res, vector<int>ans, int sum, int targetSum)
{
    if(root == NULL)
    {
        return ;
    }
    
    if(root -> left == NULL && root->right == NULL)
    {
        sum += root->val;
        ans.push_back(root->val);
        if(sum == targetSum)
        {
            res.push_back(ans);
            return;
        }
    }
    
    ans.push_back(root->val);
    solve(root->left, res, ans, sum + root->val, targetSum);
    solve(root->right, res, ans, sum + root->val, targetSum); 
    
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    vector<vector<int>> res ;
    vector<int>ans ;
    solve(root, res, ans, 0, targetSum);  
    return res;
}
};