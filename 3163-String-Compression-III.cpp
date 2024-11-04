class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int i = 0 , j = i + 1;
        string res = "";
        while(j <= n){
            int count = 0;
            while(word[i] == word[j]){
                count++;
                j++;
                if(count == 9){
                    res += to_string(count);
                    res += word[i];
                    count = 0;
                }
            }
            if(count >= 0){
                    res += to_string(count + 1);
                    res += word[i];
            }
            i = j;
            j++;
        }
        return res;
    }
};