class Trie {
    struct TrieNode
    {
        bool isTerminal;
        
        TrieNode* child[26];
        
        TrieNode()
        {
            isTerminal = false;
            
            for(int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };
    
    // create root of the Trie
    
    TrieNode* root = new TrieNode();
    
    // function for inserting word in the trie
    public:
    void insert(string word) {
        
        int n = word.size();
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';
            
            if(curr -> child[idx] == NULL)
            {
                curr -> child[idx] = new TrieNode();
            }
            
            curr = curr -> child[idx];
        }
        
        curr -> isTerminal = true;
    }
    
    // function for searching the word in the trie
    
    bool search(string word) {
        
        int n = word.size();
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';
            
            if(curr -> child[idx] == NULL)
                return false;
            
            curr = curr -> child[idx];
        }
        
        return curr -> isTerminal;
    }
    
    bool startsWith(string prefix) {
        
        int n = prefix.size();
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n; i++)
        {
            int idx = prefix[i] - 'a';
            
            if(curr -> child[idx] == NULL)
                return false;
            
            curr = curr -> child[idx];
        }
        
        return true;
        
    }
};
