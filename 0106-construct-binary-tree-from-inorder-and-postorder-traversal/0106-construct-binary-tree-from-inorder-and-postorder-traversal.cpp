/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, int instart, int inend,
                    vector<int>& postorder, int poststart, int postend,
                    map<int, int>& mp) {
        if (instart > inend || poststart > postend)
            return NULL;

        TreeNode* node = new TreeNode(postorder[postend]);
        int inorderootindex = mp[node->val];
        int numsleft = inorderootindex - instart;

        node->left = solve(inorder, instart, inorderootindex - 1, postorder,
                           poststart, poststart + numsleft-1, mp);

        node->right = solve(inorder, inorderootindex+1, inend, postorder,
                          poststart + numsleft ,postend-1, mp);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
       TreeNode* root = solve(inorder, 0, n - 1, postorder, 0, postorder.size() - 1, mp);
        return root;
    }
};