class Solution{
  public:
    void inorder(Node* root, vector<int>& inOrder) {
        if(!root) return ;
        
        inorder(root->left, inOrder);
        inOrder.push_back(root->data);
        inorder(root->right, inOrder);
    }
    
    void BST(Node* root, vector<int>& inOrder, int& i) {
        
        if(!root) return ;
        
        BST(root->left, inOrder, i);
        
        root->data = inOrder[i++];
        
        BST(root->right, inOrder,i);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> inOrder;
        inorder(root, inOrder);
        
        sort(inOrder.begin(),inOrder.end());
        
        int i=0;
        BST(root, inOrder, i);
        
        return root;
    }
};
