class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void inOrder(Node* root, vector<int>& inorder) {
        if(root == NULL)
          return ;
          
        inOrder(root->left, inorder);
        inorder.push_back(root->data);
        inOrder(root->right, inorder);
    }
    
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
      vector<int> inorder;
      inOrder(root, inorder);
      
      int i=0;
      int j = inorder.size() - 1;
      
      while(i < j) {
          int sum = inorder[i] + inorder[j];
          
          if(sum == target) 
            return true;
            
          else if(sum < target)
            i++;
            
          else
            j--;
      }
      return false;
    }
};
