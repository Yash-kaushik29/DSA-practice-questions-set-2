class LRUCache {
public:
    class node {
        public:
          int _key, _value;
          node* next;
          node* prev;

          node(int k, int value) {
              _key=k;
              _value=value;
          }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int capacity;
    unordered_map<int, node*> mp;

    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity=cap;
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(node* curr) {
        node* temp = head->next;
        curr->next = temp;
        temp->prev = curr;
        head->next = curr;
        curr->prev = head;
    }

    void deleteNode(node* curr) {
        node* delPrev = curr->prev;
        node* delNext = curr->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    //Function to return value corresponding to the key.
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            node* resNode = mp[key];
            int res = resNode->_value;
            mp.erase(key);

            // Delete from the previous position and store it in the front(used recently)
            deleteNode(resNode);
            insertNode(resNode);

            // update m[key] with new position
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        // Delete the last node(least recently used)
        if(mp.size() == capacity) {
            mp.erase(tail->prev->_key);
            deleteNode(tail->prev);
        }
        
        //update the new node
        insertNode(new node(key, value));
        mp[key] = head->next;
    }
};
