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
  int mlevel = 0;

  void sol(TreeNode* root,int level){
      
      if(root==NULL){
          return ;
      }
      mlevel=max(level,mlevel);
      sol(root->right,level+1);

      sol(root->left,level+1);
      
  }
    int maxDepth(TreeNode* root) {
      if(root==NULL){
          return 0;
      }
        sol(root,1);
        return  mlevel;
    }
};