class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        vector<int> ans;
        deque<int> dq;
        int i=0, j=0;
        
        while(j < n) {
            
            // pop the last element if it is smaller than arr[j]
            while(!dq.empty() and dq.back() < arr[j])  dq.pop_back();
            dq.push_back(arr[j]);
            
            // checking for first window
            if(j-i+1 < k) {
                j++;
            }
            // sliding window
            else {
                ans.push_back(dq.front());
                
                // if the greatest elemnt is present at the beginning of the window pop it from deque
                if(dq.front() == arr[i]) 
                  dq.pop_front();
                i++;
                j++;
            }
        }
        
        return ans;
    }
};
