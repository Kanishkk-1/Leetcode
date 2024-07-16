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
    bool findpath(TreeNode* root, vector<TreeNode*>& v, int t) {
        if (!root)
            return false;
        v.push_back(root);
        if (root->val == t)
            return true;
        if (findpath(root->left, v, t) || findpath(root->right, v, t))
            return true;
        v.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int s, int d) {
        if (!root)
            return "";
        vector<TreeNode*> v1, v2;
        string ans = "";
        findpath(root, v1, s);
        findpath(root, v2, d);
        int k = 0, n = v1.size(), m = v2.size();
        while (k < min(n, m) && v1[k] == v2[k])
            k++;
        for (int i = k; i < n; i++)
            ans += "U";
        for (int i = k; i < m; i++) {
            if (v2[i - 1]->left == v2[i])
                ans += "L";
            else
                ans += "R";
        }
        return ans;
    }
};