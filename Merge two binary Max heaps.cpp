class Solution{
    public:
    void heapify(vector<int>& arr, int n, int i)  
    {
      // Your Code Here
      int largest=i;

        // Formula
        int left=2*i+1;
        int right=2*i+2;

        if(left<n and arr[largest]<arr[left])
            largest=left;

        if(right<n and arr[largest]<arr[right])
            largest=right;

        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        } 
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(auto i: a)
          ans.push_back(i);
        for(auto j: b)
          ans.push_back(j);
          
        int size = ans.size();  
        for(int i=size/2-1; i>=0; i--) {
            heapify(ans, size, i);
        }  
        
        return ans;
    }
};
