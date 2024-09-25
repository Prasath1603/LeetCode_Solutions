class Trie {
public:
    struct node {
        struct node * child[26] = {NULL};
        bool isEnd=false;
    };
    node* root = new node();
    void insert(string word) {
        node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->child[word[i] - 'a']) {
                temp = temp->child[word[i] - 'a'];
            } else {
                node* obj = new node();
                temp->child[word[i] - 'a'] = obj;
                temp = obj;
            }
        }
        temp->isEnd = true;
    }

    bool search(string word) {
        node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->child[word[i] - 'a']) {
                temp = temp->child[word[i] - 'a'];
            } else {
                return false;
            }
        }
        if (temp->isEnd) {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        node* temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->child[prefix[i]- 'a']) {
                temp = temp->child[prefix[i]- 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your node object will be instantiated and called as such:
 * node* obj = new node();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */