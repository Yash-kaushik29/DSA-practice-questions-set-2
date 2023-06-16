// Approach 1 : Traverse whole linked list for each element . TC=O(N^2)  SC=O(1)

// Approach 2 : Sort the LL and remove the duplicates . TC=O(NlogN)  SC=O(1) 

// Approach 3 : using map . TC=O(N) SC=O(N)


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int, int> mp;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr) {
            if(mp[curr->data] > 0) {
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete(temp);
            }
            else {
                mp[curr->data]++;
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
