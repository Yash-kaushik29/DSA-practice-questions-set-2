class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q;
      vector<int> v;
      
      q.push(node);
      
      while(!q.empty()) {
          Node* temp = q.front();
          q.pop();
          
          if(temp->data != -1) {
              v.push_back(temp->data);
          }
          
          if(temp->left) {
              q.push(temp->left);
          }
          
          if(temp->right) {
              q.push(temp->right);
          }
      }
      return v;
    }
};
