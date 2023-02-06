class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], long long n){
        // code here
        
        stack<long long> s;
        long long ans=0;
        
        for(long long i=0; i<n; i++) {
            while(!s.empty() && a[s.top()]<a[i]) {
                long long cur=s.top();
                s.pop();
            if(s.empty()) {
                break;
            }
            long long diff=i-s.top()-1;
            ans+=(min(a[s.top()],a[i]) - a[cur]) * diff;
        }
        s.push(i);
    } 
        return ans;
    }
};
