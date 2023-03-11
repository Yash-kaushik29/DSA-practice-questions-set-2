class Solution{
  public:
    TNode* BST(int i, int j, vector<int>& v){

        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        
        if((j-i+1)%2 == 0) mid++;
        
        TNode* root = new TNode(v[mid]);
        root->left = BST(i, mid-1, v);
        root->right = BST(mid+1, j, v);
        return root;
    }
  
    TNode* sortedListToBST(LNode *head) {
        //code here
        vector<int>v;
        while(head){
            v.push_back(head->data);
            head=head->next;
        }
        int i=0, j=v.size();
        return BST(i, j-1, v);
    }
};
