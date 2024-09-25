class Solution {
public:
    struct node {
        struct node* child[26] = {NULL};
        bool isEnd = false;
        int count = 0;
    } ;
    node* root = new node();
    void insert(string word) {
        node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->child[word[i] - 'a']) {
                temp = temp->child[word[i] - 'a'];
                temp -> count +=1;
                // cout<<word[i]<<" "<<temp->count<<endl;
            } else {
                
                node* obj = new node();
                temp->child[word[i] - 'a'] = obj;
                obj->count = 1;
                // cout<<word[i]<<" "<<temp->count<<endl;
                temp = obj;
                
            }
        }
    }
    int traverse(string word) {
        int total = 0;
        node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->child[word[i] - 'a']) {
                // cout<<word[i]<<" "<<temp->count<<endl;
                temp = temp->child[word[i] - 'a']; 
                total += temp->count;

            }

        }
        return total;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string i : words){
            // cout<<i<<endl;
            insert(i);
        }
        vector<int> result;
        for(string i : words){
            
            int x = traverse(i);
            result.push_back(x);
        }
        return result;
    }
};