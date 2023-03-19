class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new TrieNode()) {}
    
    ~WordDictionary() {delete root;}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWord(word,0,root);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word,0,root);
    }
private:
    struct TrieNode {
        TrieNode():child(vector<TrieNode*>(26,NULL)), isLeaf(false) {}
        ~TrieNode() {for(TrieNode* node:child) delete node;}
        vector<TrieNode*> child;
        bool isLeaf;
    };
    
    TrieNode* root;
    
    void addWord(const string& word, size_t i, TrieNode* cur) {
        if(i==word.length()) return;
        size_t j = word[i] - 'a';
        if(!cur->child[j]) cur->child[j] = new TrieNode();
        if(i==word.length()-1) cur->child[j]->isLeaf=true;
        addWord(word,i+1,cur->child[j]);
    }
    
    bool search(const string& word, size_t i, TrieNode* cur) const {
        if(i==word.length()) return false;
        
        if(word[i]!='.') {
            size_t j = word[i] - 'a';
            if(!cur->child[j]) return false;
            if(i==word.length()-1 && cur->child[j]->isLeaf) return true;
            return search(word,i+1,cur->child[j]);
        }
        else {
            for(TrieNode* node:cur->child) {
                if(node) {
                    if(i==word.length()-1 && node->isLeaf) return true;
                    if(search(word,i+1,node)) return true;
                }
            }
            return false;
        }
    }
    
};








































/*struct Node{
    Node* link[26];
    bool last;
    
    Node(){
        last = false;
        memset(link, 0, sizeof(link));
    }
    
    bool have(char ch){
            return (link[ch -'a'] != NULL);
    }
    
    Node *get(char ch){
        return link[ch-'a'];
    }
    void setLast(){
        this->last = true;
    }
    bool getLast(){
        return this->last;
    }
    
    void insert(char ch, Node *node){
        link[ch -'a'] = node;
    }
};
class WordDictionary {
    private:
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *tmp = root;
        for(int i = 0 ; i < word.length() ; i++)
        {
            if(!tmp->have(word[i]))
                tmp->insert(word[i], new Node());
            tmp = tmp->get(word[i]);
        }
        tmp->setLast();
    }
    
    bool search(string word) {
        return searchInd(word, 0);
    }
    bool searchInd(string word, int ind)
    {
        Node* tmp = root;
        int i = 0; bool ok = false;
        for(i = ind ; i < word.length(); i++)
        {
            if(word[i] != '.'){
                if(!tmp->have(word[i])) return false;
                tmp = tmp->get(word[i]);
            }
            else{
                for(int j = 0 ; j < 26; j++){
                    
                    if(tmp->link[j] != NULL){
                        
                        if(i + 1 == word.length()){
                            cout << tmp->link[j]->getLast() << " " << j<< endl ;
                            return tmp->link[j]->getLast();
                        }
                        ok = ok | searchInd(word, i + 1);
                    }
                }
            }
        }
        if(i == word.length())
            ok = ok | tmp->getLast();
        return ok;
    }
};*/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */