// Approach 1: using maps

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        map<Node* , bool> m;
        Node* temp=head;

        if(head==NULL)
        return false; 
        
        while(temp!=NULL) {
            if(m[temp]==false) {
                m[temp]=true;
            }
            else {
                return true;
            }
            temp=temp->next;
        }
        
        return false;
    }
};

// Approach 2: Floyd cycle detection algorithm

bool detectLoop(Node* head)
    {
        // your code here
        Node *slow=head;
        Node* fast=head;
        
        while(fast != NULL) {
            fast=fast->next;
            
            if(fast != NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
            
            if(slow == fast)
            return 1;
        }
        
        return 0;
