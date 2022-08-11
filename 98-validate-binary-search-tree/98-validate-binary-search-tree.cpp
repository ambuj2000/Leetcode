class Solution {
public:
    long compare = LONG_MIN;
    bool ans = true;
    void inorder(TreeNode* root)
    {
        if(ans == true){
            if(root == NULL)
                return;
            inorder(root->left);
            if(compare < root -> val)
                compare = root -> val;
            else
                ans = false;
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL)
            true;
        inorder(root);
        return ans;            
    }
};