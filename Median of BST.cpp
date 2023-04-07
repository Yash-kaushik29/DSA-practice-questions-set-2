void countNodes(Node *root, int& n) {
    if(!root) return ;
    
    countNodes(root->left, n);
    n++;
    countNodes(root->right, n);
}

void solve(Node *root, Node* &curr, Node* &prev, int& c, int k, int& f) {
    if(!root) return ;
    
    solve(root->left, curr, prev, c, k, f);
    
    // For first element 
    if(prev==NULL) {
        c++;
        prev=root;
    }
    // Element is found
    else if(c==k) {
        curr=root;
        c++;
        f=1;
        return ;
    }
    // If element is not found yet update the previous pointer
    else if(f==0) {
        c++;
        prev=root;
    }
    
    solve(root->right, curr, prev, c, k, f);
}

float findMedian(struct Node *root)
{
      int n=0;
      countNodes(root, n);
      
      int c=1;
      int found=0;
      Node* curr=NULL;
      Node* prev=NULL;
      int k=(n/2)+1;
      
      solve(root, curr, prev, c, k, found);
      
      if(n & 1) {
          return (curr->data)*1.0;
      }
      return ((curr->data+prev->data)*1.0)/2.0;
}
