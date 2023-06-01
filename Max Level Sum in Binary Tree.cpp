class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        queue<Node*> q;
        q.push(root);
        int maxSum=INT_MIN;

        while(!q.empty()) {
            int size = q.size();
            int currSum=0;

            while(size--) {
                Node* front = q.front();
                q.pop();

                currSum+=front->data;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            
            if(currSum > maxSum) {
                maxSum = currSum;
            }
        }
        return maxSum;
    }
};

