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

    unordered_map<int, TreeNode*> mp;

    bool dfs(TreeNode* root, long long low, long long high) {

        if (root == NULL) {
            return true;
        }

        // Validate BST
        if (root->val <= low || root->val >= high) {
            return false;
        }

        // If current node is a leaf, try merging
        if (root->left == NULL && root->right == NULL) {

            if (mp.find(root->val) != mp.end()) {

                TreeNode* node = mp[root->val];

                // Merge the tree
                root->left = node->left;
                root->right = node->right;

                mp.erase(root->val);
            }
        }

        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {

        // Store all roots
        for (auto root : trees) {
            mp[root->val] = root;
        }

        // Find final root
        unordered_set<int> leaves;

        for (auto root : trees) {
            if (root->left) leaves.insert(root->left->val);
            if (root->right) leaves.insert(root->right->val);
        }

        TreeNode* root = NULL;

        for (auto node : trees) {
            if (leaves.find(node->val) == leaves.end()) {
                root = node;
                break;
            }
        }

        if (root == NULL) return NULL;

        // Root should not be merged into another tree
        mp.erase(root->val);

        // Validate and merge
        if (!dfs(root, LLONG_MIN, LLONG_MAX)) {
            return NULL;
        }

        // All other trees must be used
        if (!mp.empty()) {
            return NULL;
        }

        return root;
    }
};
