class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        vector<int> freq(256,0);
        int start = 0;
        for(int i = 0 ; i < s.size() ; i++){
            freq[s[i]]++;

            while(freq[s[i]] > 1){
                freq[s[start]]--;
                start++;
            }

            length = max(length , i - start + 1);
        }
        return length;
    }
};