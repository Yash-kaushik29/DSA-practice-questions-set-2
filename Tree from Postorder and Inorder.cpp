int findPos(int in[], int ele, int s, int e) {
        for(int i = s; i <= e; i++) {
            if(in[i] == ele) {
                return i;
            }
        }
        return -1;
}
    
Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n) {
        //base case
        if(index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = post[index--];
        Node* root = new Node(element);
        int pos = findPos(in, element, inorderStart, inorderEnd);
        
        root->right = solve(in, post, index, pos+1, inorderEnd, n);
        root->left = solve(in, post, index, inorderStart, pos-1, n);
        
        return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex = n-1;
    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n);
    return ans;
}
