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
    vector<int> preorderTraversal(TreeNode* root) {
           vector<int> v;
        if (root == NULL)
            return v;
        stack<TreeNode*> s;

        s.push(root);
        while (!s.empty()) {
         
            int n = s.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = s.top();
                s.pop();
                v.push_back(node->val);
                  if (node->right != NULL)
                    s.push(node->right);
                if (node->left != NULL)
                    s.push(node->left);
              
            }
        }
        return v;
    }
};