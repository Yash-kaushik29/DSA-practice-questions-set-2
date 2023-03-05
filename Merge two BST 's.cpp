class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inOrder(Node* root, vector<int>& in) {
        if(root == NULL)
          return ;
          
        inOrder(root->left, in);
        in.push_back(root->data);
        inOrder(root->right, in);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> a, b;
       inOrder(root1, a);
       inOrder(root2, b);
       
       vector<int> ans(a.size() + b.size());
        int i=0,j=0,k=0;
        
        while(i < a.size() && j < b.size()) {
            
            if(a[i] < b[j]) {
                ans[k] = a[i];
                k++; i++;
            }
            else {
                ans[k] = b[j];
                k++; j++;
            }
        }
        
        while(i < a.size()) {
            ans[k] = a[i];
                k++; i++;
        }
            
        while(j < b.size()) {
            ans[k] = b[j];
                k++; j++;   
        }
            
        return ans;  
    }
};
