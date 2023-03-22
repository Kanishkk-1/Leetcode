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
vector<int>v;
     TreeNode* sol(TreeNode* root,int val){
         if(root==NULL){
             return NULL;
         }

         if(val>root->val){
           return sol(root->right,val);
         }
         
         if(val<root->val){
             return sol(root->left,val);
         }


         if(root->val==val){
            // v.push_back(root->val, root->left, root->right);
            return root;
         }

         return NULL;
 }
    TreeNode* searchBST(TreeNode* root, int val) {
        return sol(root,val);
    }
};