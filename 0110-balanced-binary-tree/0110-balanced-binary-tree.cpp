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
public:int maxdepth(TreeNode* root){
   if (root == NULL) return 0;
        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);
        return 1 + max(lh, rh);
    return (1+max(lh,rh));
}

public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);

        if(abs(lh-rh)>1) return false;
         return isBalanced(root->left) && isBalanced(root->right);
    }
};