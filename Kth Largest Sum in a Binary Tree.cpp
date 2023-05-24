class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long sum=0;

            while(size--) {
                TreeNode* front = q.front();
                q.pop();
                sum+=front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(pq.size() < k) {
                pq.push(sum);
            }
            else {
                if(sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        return pq.size()==k ? pq.top() : -1;
    }
};
