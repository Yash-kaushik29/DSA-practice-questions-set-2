class Solution
{
    public:
    class Node {
        public:
           int data;
           int i;
           int j;
        Node(int data, int row, int col) {
            this->data = data;
            i = row;
            j = col;
        }   
    };
    
    class compare {
        public:
           bool operator()(Node* a, Node* b) {
               return (a->data > b->data);
           }
    };
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        // Step 1: Insert first element of each array
        for(int i=0; i<K; i++) {
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        vector<int> ans;
        
        while(!pq.empty()) {
            
            Node* temp = pq.top();
            ans.push_back(temp->data);
            pq.pop();
            
            int i = temp->i;
            int j = temp->j;
            
            if(j+1 < arr[i].size()) {
                Node* next = new Node(arr[i][j+1], i, j+1);
                pq.push(next);
            }
        }
        return ans;
    }
};
