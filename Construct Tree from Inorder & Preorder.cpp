class Solution{
    public:
    int findPos(int in[], int ele, int s, int e) {
        for(int i = s; i <= e; i++) {
            if(in[i] == ele) {
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        //base case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = findPos(in, element, inorderStart, inorderEnd);
        
        root->left = solve(in, pre, index, inorderStart, pos-1, n);
        root->right = solve(in, pre, index, pos+1, inorderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};
