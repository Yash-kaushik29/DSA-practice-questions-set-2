class Solution {
public:
    void traverseLeft(Node* root, vector<int>& ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return ;
        }
        
        ans.push_back(root->data);
        if(root->left) {
            return traverseLeft(root->left,ans);
        }
        if(root->right) {
            return traverseLeft(root->right,ans);
        }
    }
    
    void traverseleaf(Node* root, vector<int>& ans) {
        if(root == NULL)
         return ;
         
        if(root->left == NULL && root->right ==NULL) {
            ans.push_back(root->data);
        } 
        
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }

    void traverseRight(Node* root, vector<int>& ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return ;
        }
    
        if(root->right) {
            traverseRight(root->right,ans);
        }
        else {
            traverseRight(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
        traverseRight(root->right,ans);
        
        return ans;
    }
};
