vector<vector<int>> levelOrder(Node* root)
{
        vector<vector<int>> ans;
        queue<Node*> q;

        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            while(size--) {
                Node* front = q.front();
                q.pop();
                temp.push_back(front->data);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(temp);
        }
        return ans;
}
