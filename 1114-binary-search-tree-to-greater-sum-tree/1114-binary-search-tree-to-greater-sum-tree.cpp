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
	void util(TreeNode* root, int& sum) {
		if(!root) return;
		if(!root->left && !root->right) {
			root->val=sum+root->val;
			sum=root->val;
			return;
		}

		util(root->right,sum);
		root->val=sum+root->val;
		sum=root->val;
		util(root->left, sum);
	}

	TreeNode* bstToGst(TreeNode* root) {
		int sum=0;
		util(root, sum);
		return root;    
	}
};