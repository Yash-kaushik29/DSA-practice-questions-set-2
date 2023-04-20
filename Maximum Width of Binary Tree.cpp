class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
          return 0;

        queue<pair<TreeNode*, int> > q;
        q.push({root,0});

        long long ans=0;

        while(!q.empty()) {
            int size = q.size();
            long long first = q.back().second;
            long long second = q.front().second;

            for(int i=0; i<size; i++) {
                TreeNode* front = q.front().first;
                long long index = q.front().second;
                q.pop();
                
                if(front->left) {
                    q.push({front->left, 2*index+1});
                }

                if(front->right) {
                    q.push({front->right, 2*index+2});
                }
            }
            ans = max(ans, first-second+1);
        }
        return ans;  
    }
};
