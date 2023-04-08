class Solution{
    class Node{
      public:
        int data;
        Node*left;
        Node*right;
        Node(int data) {
           this->data=data;
           left=NULL;
           right=NULL;
        }
    };
    
    
    public:
    Node* solve(Node* root, int data, int &succ) {
        
        if(!root) {
            Node* q = new Node(data);
            return q;
        }
        
        if(data < root->data) {
            succ = root->data;
            root->left = solve(root->left, data, succ);
        }
        
        else if(data >= root->data) {
            root->right = solve(root->right, data, succ);
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        Node* root = NULL;
        
        for(int i=n-1; i>=0; i--) {
            int succ = -1;
            
            root = solve(root, arr[i], succ);
            
            arr[i] = succ;
        }
        return arr;
    }
};
