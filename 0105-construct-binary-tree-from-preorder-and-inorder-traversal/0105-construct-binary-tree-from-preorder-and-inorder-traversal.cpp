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
private:
TreeNode* solve (vector<int>& preorder , int prestart , int preEnd ,  vector<int>& inorder , int instart , int inend , map<int ,int >& mp){
    if(prestart>preEnd || instart > inend) return NULL;

    TreeNode* node =new TreeNode(preorder[prestart]);

    int inorderootindex = mp[node->val];

    int numsleft = inorderootindex - instart;

    node->left = solve(preorder , prestart+1 , prestart + numsleft , inorder , instart , inorderootindex-1 , mp );
    node->right = solve(preorder , prestart+numsleft+1 , preEnd , inorder ,inorderootindex+1 , inend , mp );

    return node;
}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int ,int >mp;
        int n =inorder.size();
        for(int i=0;i<n ;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = solve(preorder , 0 , preorder.size()-1 , inorder , 0 , n-1 , mp);
        return root;
    }
};