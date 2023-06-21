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
bool isSymmetricTest(TreeNode* leftnode, TreeNode* rightnode){
    if(leftnode==NULL && rightnode==NULL)
    return true;

    if (leftnode==NULL||rightnode==NULL||leftnode->val!=rightnode->val)
    return false;

return isSymmetricTest(leftnode->left, rightnode->right) && isSymmetricTest(leftnode->right, rightnode->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
         return 0;
        }
        
        return isSymmetricTest(root->left , root->right);

    }
};