class MagicDictionary {
public:
    set<string> st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s : dictionary) st.insert(s);
    }
    
    bool search(string searchWord) {
        for(int i = 0 ; i < searchWord.size() ; i++){
            char t = searchWord[i];
            for(char c = 'a' ; c <= 'z' ; c++){
                if(c == t) continue;
                searchWord[i] = c;
                if(st.count(searchWord)) return true;
                searchWord[i] = t;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */