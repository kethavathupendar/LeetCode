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
    int ans = 0;

    // {isBST, sum, minVal, maxVal}
    vector<int> solve(TreeNode* root) {

        // Empty subtree is a valid BST
        if (root == NULL) {
            return {1, 0, INT_MAX, INT_MIN};
        }

        // Postorder traversal
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        // Check whether current subtree is BST
        if (left[0] && right[0] &&
            root->val > left[3] &&
            root->val < right[2]) {

            int sum = left[1] + right[1] + root->val;

            ans = max(ans, sum);

            int mini = min(root->val, left[2]);
            int maxi = max(root->val, right[3]);

            return {1, sum, mini, maxi};
        }

        // Not a valid BST
        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
