class Solution{
  public:
    void inorder(vector<int>&A, vector<int>& inOrder, int i) {
        
        if(i>=A.size())  return ;
        
        inorder(A, inOrder, 2*i+1);
        inOrder.push_back(A[i]);
        inorder(A, inOrder, 2*i+2);
    }
   
  
    int minSwaps(vector<int>&A, int n) {
        
        vector<int> inOrder;
        int i=0;
        inorder(A, inOrder, i);
        
        vector<pair<int,int> > v;
        
        for(int i=0; i<n; i++) {
            v.push_back({inOrder[i],i});
        }
        
        sort(v.begin(),v.end());
        
        int swaps=0;
        
        for(int i=0; i<n; i++) {
            if(v[i].second != i) {
                swaps++;
                swap(v[i], v[v[i].second]);
                --i;
            }
        }
        
        return swaps;
    }
};
