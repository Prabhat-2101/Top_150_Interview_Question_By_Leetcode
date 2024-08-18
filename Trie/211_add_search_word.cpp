class TrieNode{
    public:
    TrieNode* children[26]={NULL};
    bool end;
    TrieNode(){
        end = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(const char ch: word){
            int idx = ch-'a';
            if(temp->children[idx] == NULL) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->end = true;
    }
    bool searchRecur(string word,int index,TrieNode* node){
        if (index == word.size()) {
            return node->end;
        }
        
        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchRecur(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            if (node->children[idx] == NULL) {
                return false;
            }
            return searchRecur(word, index + 1, node->children[idx]);
        }
    }
    bool search(string word) {
        bool isFound = searchRecur(word,0,root);
        return isFound;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */