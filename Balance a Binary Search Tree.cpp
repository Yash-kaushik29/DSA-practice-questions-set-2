class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& inorder) {
        if(root == NULL)
          return ;

        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    TreeNode* balanced(vector<int> in, int s, int e) {
        if(s>e)
          return NULL;
    
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(in[mid]);
    
        root->left = balanced(in, s, mid-1);
        root->right = balanced(in, mid+1, e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
     	inOrder(root, inorder);
	
	    return balanced(inorder, 0, inorder.size()-1);
    }
};
