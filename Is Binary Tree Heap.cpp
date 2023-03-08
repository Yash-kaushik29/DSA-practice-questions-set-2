class Solution {
  public:
    int countNodes(struct Node* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root, int i, int c) {
        if(root == NULL)
           return true;
           
        if(i >= c)
           return false;
        else {
            bool left = isCBT(root->left, 2*i+1, c);
            bool right = isCBT(root->right, 2*i+2, c);
            return (left && right);
        }   
    }
    
    bool maxOrder(struct Node* root) {
        if(!root->left && !root->right)
           return true;
           
        if(!root->right) {
            return (root->data > root->left->data);
        }   
        else {
            bool left = maxOrder(root->left);
            bool right = maxOrder(root->right);
            return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
        }
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int count = countNodes(tree);
        
        return (isCBT(tree, index, count) && maxOrder(tree));
    }
};
