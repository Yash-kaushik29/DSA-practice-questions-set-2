vector<vector<int>> levelOrder(Node* root)
{
  //Your code here
  vector<vector<int>>v;
  if(root==NULL)
  {
      return v;
  }
  queue<Node*>q;
  q.push(root);
  
  while(q.empty()==false)
  {
      vector<int>ans;
     int count=q.size();
     if(count==0)
     {
         return v;
     }
     for(int i=0;i<count;i++)
     {
         Node*u=q.front();
         q.pop();
         ans.push_back(u->data);
         if(u->left!=NULL)
         {
             q.push(u->left);
         }
         if(u->right!=NULL)
         {
             q.push(u->right);
         }
       //  cout<<"/n";
     }
     v.push_back(ans);
  }
  return v;
}
