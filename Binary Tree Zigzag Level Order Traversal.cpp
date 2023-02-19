class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        int count=0;

        while(q.size()){
            vector<int> temp;
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                temp.push_back(node->val);
                
            }
            if(count==0){
                count=1;    
                ans.push_back(temp);
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                count=0;
            }
        }
        return ans;
    }
};
