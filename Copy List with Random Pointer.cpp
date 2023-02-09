// Approach 1 : TC = O(N) / SC = O(N)

class Solution {

private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        
        Node * newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return ;
        }
        
        else {
            tail->next = newNode;
            tail = newNode;
            return ;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        // Step 1 - Clone a LL using next pointer
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        // Step 2 - Create a map
        unordered_map<Node*,Node*> m; 
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            m[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        } 
        
        // Step 3 - copying random pointers
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL) {
            cloneNode->random = m[originalNode->random]; 
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};


// Approach 2 : TC = O(N) / SC = O(1)

class Solution {

private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        
        Node * newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return ;
        }
        
        else {
            tail->next = newNode;
            tail = newNode;
            return ;
        }
    }    

public:
    Node* copyRandomList(Node* head) {
        
        // Step 1 : Create a clone list

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
    
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        // Step 2 : add clonenodes in between original list

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            temp = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = temp;

            temp = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = temp;
        } 
        // Step 3 : copy random pointers

        temp = head;
        while(temp != NULL) {
            if(temp->next != NULL) {
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }
        // Step 4 : revert changes done in step 2

        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode !=NULL) {
            originalNode->next =  cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        // Step 5 : return ans

        return cloneHead;
    }
};
