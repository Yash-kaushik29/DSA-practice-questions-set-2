class Solution{
    public:
    Node* LCA(Node* root, int a, int b) {
        if(!root)  return NULL;
        
        if(root->data==a or root->data==b)  return root;
        
        Node* l = LCA(root->left, a, b);
        Node* r = LCA(root->right, a, b);
        
        if(l and r) return root;
        if(l) return l;
        return r;
    }
    
    int distance(Node* root, int key) {
        if(!root) return 0;
        
        if(root->data == key) return 1;
        
        int x = distance(root->left, key);
        int y = distance(root->right, key);
        
        if(!x and !y) return 0;
        else return x+y+1;
    }
    
    
    int findDist(Node* root, int a, int b) {
        
        Node* lca = LCA(root, a, b);
        int x = distance(lca, a);
        int y = distance(lca, b);
        
        return x+y-2;
    }
};
