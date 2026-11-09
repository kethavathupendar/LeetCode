
class BSTIterator {
public:

    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {

        pushAll(root);
    }

    void pushAll(TreeNode* node) {

        while (node != NULL) {

            st.push(node);
            node = node->left;
        }
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        int value = node->val;

        // If right subtree exists,
        // push its leftmost path
        if (node->right != NULL) {

            pushAll(node->right);
        }

        return value;
    }

    bool hasNext() {

        return !st.empty();
    }
};
