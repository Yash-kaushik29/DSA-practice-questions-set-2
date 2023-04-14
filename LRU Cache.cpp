class LRUCache
{
    class node {
        public: 
          int _key, _value;
          node* prev;
          node*next;

          node(int k, int v) {
              _key = k;
              _value = v;
          }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int capacity;
    unordered_map<int, node*> m;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
       capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void InsertNode(node* curr) {
        node* temp = head->next;
        curr->next = temp;
        curr->prev =  head;
        head->next = curr;
        temp->prev = curr;
    }

    void DeleteNode(node* curr) {
        node* delPrev = curr->prev;
        node* delNext = curr->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(m.find(key) != m.end()) {
            node* resNode = m[key];
            int res = resNode->_value;
            m.erase(key);

            // Delete from the previous position and store it in the front(used recently)
            DeleteNode(resNode);
            InsertNode(resNode);
            
            // update m[key] with new position
            m[key] = head->next;
            return res;
        }

        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
           if(m.find(key) != m.end()) {
            node* existingNode = m[key];
            m.erase(key);
            DeleteNode(existingNode);
        }

        if(m.size() == capacity) {
            // Delete the last node(least recently used)
            m.erase(tail->prev->_key);
            DeleteNode(tail->prev);
        }
        
        //update the new node
        InsertNode(new node(key, value));
        m[key] = head->next;
    }
};
