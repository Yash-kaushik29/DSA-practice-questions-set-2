class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        priority_queue<int, vector<int>, greater<int> > pq;
        int n = Arr.size();
        
        for(int i=0; i<n; i++) {
            int sum =0;
            
            for(int j=i; j<n; j++) {
                sum+=Arr[j];
                
                if(pq.size() < K) {
                    pq.push(sum);
                }
                else {
                    if(sum > pq.top()) {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};
