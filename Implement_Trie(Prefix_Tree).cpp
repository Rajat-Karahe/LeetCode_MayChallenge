class TrieNode{
public:    
    char data;
    TrieNode** children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;
    
    void insertWord(TrieNode *root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        int index = word[0]-'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertWord(child, word.substr(1));
    }
    
    bool searchWord(TrieNode *root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        
        int index = word[0]-'a';
        TrieNode *child = root->children[index]; 
        if(child != NULL){
            return searchWord(child, word.substr(1));
        }
        
        return false;
    }
    
    bool startsWithWord(TrieNode *root, string prefix){
        if(prefix.length() == 0){
            return true;
        }
        
        int index = prefix[0]-'a';
        TrieNode *child = root->children[index]; 
        if(child != NULL){
            return startsWithWord(child, prefix.substr(1));
        }
        
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertWord(root, word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchWord(root, word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithWord(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
