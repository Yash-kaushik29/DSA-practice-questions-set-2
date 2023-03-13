class Solution {
public:
    bool check(TreeNode* left,TreeNode* right){

        if(!left and !right)
            return true;

        if((left != NULL and right == NULL) || (left == NULL and right != NULL) || (left->val != right->val))
            return false;
        if(left->val == right->val)
            return check(left->right,right->left) && check(left->left,right->right);
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {

        if(!root)
            return true;
        return check(root->left,root->right);
        
    }
};
