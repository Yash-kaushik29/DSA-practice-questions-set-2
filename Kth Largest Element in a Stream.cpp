class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > min_pq;
    int pos;

    KthLargest(int k, vector<int>& nums) {
        pos=k;
        for(auto num: nums) {
            if(min_pq.size()<k) {
                min_pq.push(num);
            }
            else if(min_pq.top() < num) {
                min_pq.pop();
                min_pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if(min_pq.size() < pos) {
            min_pq.push(val);
        }
        else if(min_pq.top() < val){
            min_pq.pop();
            min_pq.push(val);
        }
        return min_pq.top();
    }
};
