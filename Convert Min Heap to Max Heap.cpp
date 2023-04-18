class Solution{
public:
    void heapify(vector<int>& arr, int index, int N) {
        int largest = index;
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        
        if(leftChild < N and arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }
        
        if(rightChild < N and arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }
        
        if(largest != index) {
            swap(arr[largest], arr[index]);
            heapify(arr, largest, N);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N){
        
        for(int i=N/2-1; i>=0; i--) {
            heapify(arr, i, N);
        }
    }
};
