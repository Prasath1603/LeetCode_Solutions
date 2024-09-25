class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> f1(26,0);
        // vector<int> f2(26,0);
        for(char i : s){
            f1[i-'a']++;
        }
        for(char i : t){
            f1[i-'a']--;
        }
        for(int i=0;i<26;i++){
            if(f1[i]<0){
                return i+'a';
            }
        }
        return 'x';
        
    }
};