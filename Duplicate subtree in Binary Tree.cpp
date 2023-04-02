class Solution {
  public:
    unordered_map<string,int> m;
    string solve(Node* root) {
      if(!root)  return "#";
      string s="";
      
      if(!root->left and !root->right) {
         s=to_string(root->data);    
         return s+"#";
      }
      
      s += to_string(root->data)+"#";
      s += solve(root->left)+"#";
      s += solve(root->right)+"#";
      
      m[s]++;
      return s;
    }
    
    int dupSub(Node *root) {
         m.clear();
         solve(root);
         
         for(auto it: m) {
             if(it.second >= 2)  return 1;
         }
         
         return 0;
    }
};
