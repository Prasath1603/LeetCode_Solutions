class Trie {
public:
    Trie* child[10];
    Trie() {
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr;
        }
    }
};

class Solution {
public:
    vector<int> v;

    void dfs(Trie* r, int val, int n) {
        if (val > n) 
            return;
        v.push_back(val);
        for (int i = 0; i < 10; i++) {
            int newVal = val * 10 + i; 
            if (newVal <= n) {
                if(r->child[i] == nullptr){
                    r->child[i] = new Trie();
                }
                dfs(r->child[i], newVal, n);  
            } else {
                break;  
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        Trie* root = new Trie();
        for (int i = 1; i <= 9; i++) {  
            dfs(root, i, n);  
        }

        return v;
    }
};
