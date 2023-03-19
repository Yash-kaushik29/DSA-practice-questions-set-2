class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isTerminal;

        TrieNode() {
            isTerminal=false;
            for(int i=0; i<26; i++) {
               children[i]=NULL;
            }  
        }
    };

    TrieNode* root;

    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
       TrieNode* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if(node->children[idx]==NULL) 
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isTerminal = true;
    }
    
    bool search(string word) {
         return searchHelper(word, root);
    }


    bool searchHelper(string word, TrieNode* node){

        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c: node->children)
                    if(c && searchHelper(word.substr(i+1), c)) 
                        return true;
                return false;
            }
            int idx = ch - 'a';
            if(node->children[idx]==NULL) 
                return false;
            node = node->children[idx];
        }
        return node->isTerminal;
    }
};
