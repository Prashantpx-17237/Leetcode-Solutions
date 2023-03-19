struct node{
    public:
        node()
        {
            for(int i = 0 ; i < 26 ; i++)
                next[i] = NULL;
        }
    node* next[26];
    bool last = false;
    
    bool have(char ch){
        return (next[ch - 'a'] != NULL);
    }
    
    node *get(char ch){
        return next[ch - 'a'];
    }
    
    void insert(char ch){
        node *tmp = new node();
        next[ch - 'a'] = tmp;
    }
};
class Trie {
    private:
    
    node* root;

    public:
    
    Trie() {
       root = new node;
    }
    
    void insert(string word) {
        node* tmp = root;
        for(int i = 0 ; i < word.length() ; i++)
        {
            if(!tmp -> have(word[i])){
                tmp -> insert(word[i]);
            }
             tmp = tmp -> get(word[i]);
        }
        tmp -> last = true;
    }
    
    bool search(string word) {
        node * tmp = root;
        for(int i = 0 ; i < word.length() ; i++)
        {
            if(!tmp -> have(word[i]))
                return false;
            tmp = tmp->get(word[i]);
        }
        return tmp -> last;
    }
    
    bool startsWith(string prefix) {
        node * tmp = root;
        for(int i = 0 ; i < prefix.length() ; i++)
        {
            if(!tmp -> have(prefix[i]))
                return false;
            tmp = tmp->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */