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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL) return v;
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright = true;
        while(!q.empty()){
            int n = q.size();
            vector<int>ans(n);
            for(int i =0; i < n ;i++){
                TreeNode* node = q.front();
                q.pop();
                int index = lefttoright ? i: (n -1 -i);
                ans[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lefttoright = !lefttoright;
            v.push_back(ans);
        }
        return v;
    }
};