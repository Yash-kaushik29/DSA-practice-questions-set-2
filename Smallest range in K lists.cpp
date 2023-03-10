class Solution{
    public:
    class  node {
        public:
          int data;
          int row;
          int col;
          
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }  
    };
    
    class compare {
      public:
      bool operator()(node* a, node* b) {
          return (a->data > b->data);
      }
    };
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int mini=INT_MAX, maxi=INT_MIN;
          priority_queue<node*, vector<node*>, compare> pq;
          
          for(int i=0; i<k; i++) {
              int ele = KSortedArray[i][0];
              mini = min(mini,ele);
              maxi = max(maxi,ele);
              pq.push(new node(ele, i, 0));
          }
          
          int start=mini, end=maxi;
          
          while(!pq.empty()) {
              
              node* temp = pq.top();
              pq.pop();
              
              mini = temp->data;
              
              if((maxi - mini) < (end - start)) {
                  end = maxi;
                  start = mini;
              }
              
              if(temp->col+1 < n) {
                  maxi = max(maxi, KSortedArray[temp->row][temp->col+1]);
                  pq.push(new node(KSortedArray[temp->row][temp->col+1], temp->row, temp->col+1));
              }
              else {
                  break;
              }
          }
          
          pair<int,int> ans;
          ans = make_pair(start,end);
          
          return ans;
          
    }
};
