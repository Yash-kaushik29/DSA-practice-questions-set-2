class Solution {
public:
    int minValue(TreeNode* root) {

        while(root->left) {
            root = root->left;
        }

        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == NULL) {
            return root;
        }

        if(root->val == key) {
            // 0 child
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // 1 child

            // left child
            if(root->left && !root->right) {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }

            // right child
            if(!root->left && root->right) {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
      
            // 2 child
            if(root->left && root->right) {
                int mini = minValue(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }

        }

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        else {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};
