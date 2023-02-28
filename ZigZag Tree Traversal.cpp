class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	queue<Node*> q;
    	
        if(root == NULL){
            return ans;
        }
        
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {
            
            int size = q.size();
            vector<int> temp(size);
            
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();

                int index = leftToRight ? i : size-i-1;
                temp[index] = node->data;
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            leftToRight = !leftToRight;
                
                for(auto it: temp) {
                    ans.push_back(it);
                }
       }
       return ans;
    }    
};
