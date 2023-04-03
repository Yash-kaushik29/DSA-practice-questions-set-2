class Solution
{
public:
    int solve(Node *root1,Node* root2,int target)
    {
        if(!root1 || !root2)
            return 0;
            
        if(root1->data == target)
            return root2->data;
            
        if(root2->data == target)
            return root1->data;
            
        return solve(root1->left,root2->right,target) + solve(root1->right,root2->left,target);
    }

    int findMirror(Node *root, int target)
    {
        if(root->data == target)
            return root->data;
            
        int res=solve(root->left,root->right,target);   
        
       if(res) return res;
       
       return -1;
    }
};
