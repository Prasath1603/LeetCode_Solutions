class WordDictionary {
public:
    struct Trie{
        Trie *child[26];
        bool isEnd = false;
    };
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *temp = root;
        for(char c : word){
            int x = c - 'a';
            if(temp->child[x]){
                temp = temp->child[x];
            }
            else{
                Trie *n = new Trie();
                temp->child[x] = n;
                temp = temp->child[x];
            }
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Trie *temp = root;
        for(char &c : word){
            char tc = c;
            int x = c - 'a';
            if(c == '.'){
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    c = ch;
                    if(search(word)) return true;
                    c = tc;
                }
                return false;
            }
            if(temp->child[x]){
                temp = temp->child[x];
            }
            else return false;
        }
        return temp->isEnd ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */