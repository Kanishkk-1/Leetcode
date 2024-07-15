/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> iscreated;
        unordered_map<int, bool> isparent;
        int n = d.size();
        for (int i = 0; i < n; i++) {
            TreeNode *parent, *child;
            if (iscreated.find(d[i][0]) == iscreated.end()) {
                parent = new TreeNode(d[i][0]);
                iscreated[d[i][0]] = parent;
            } else
                parent = iscreated[d[i][0]];
            if (iscreated.find(d[i][1]) == iscreated.end()) {
                child = new TreeNode(d[i][1]);
                iscreated[d[i][1]] = child;
            } else
                child = iscreated[d[i][1]];
            if (d[i][2])
                parent->left = child;
            else
                parent->right = child;
            isparent[d[i][1]] = true;
        }
        for (int i = 0; i < n; i++)
            if (isparent.find(d[i][0]) == isparent.end())
                return iscreated[d[i][0]];
        return NULL;
    }
};