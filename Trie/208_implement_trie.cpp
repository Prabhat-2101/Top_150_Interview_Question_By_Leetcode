#define MAXSIZE 26
struct TrieNode{
    TrieNode* child[MAXSIZE];
    bool end = false;

    bool containsKey(char ch){
        return child[ch-'a'] != NULL;
    }
    void putKey(TrieNode* newNode,char ch){
        child[ch-'a'] = newNode;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(!temp->containsKey(ch)){
                temp->putKey(new TrieNode(),ch);
            } 
            temp = temp->child[ch-'a'];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])) return false;
            temp = temp->child[word[i]-'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0;i<prefix.length();i++){
            if(!temp->containsKey(prefix[i])) return false;
            temp = temp->child[prefix[i]-'a'];
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