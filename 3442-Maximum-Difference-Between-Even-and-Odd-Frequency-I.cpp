class Solution {
public:
    bool isOdd(int x){ return x & 1;}
    int maxDifference(string s) {
        vector<int> freq(26 , 0);
        for(char c : s){
            freq[c - 'a']++;
        }
        int res = INT_MIN ;
        for(int i = 0 ; i < 26 ; i++){
            if(!freq[i]) continue;
            for(int j = 0 ; j < 26 ; j++){
                if(!freq[j]) continue;
                if(isOdd(freq[i]) && !isOdd(freq[j])){
                    res = max(res , freq[i] - freq[j]);
                }
                // else if(!isOdd(freq[i]) && isOdd(freq[j])){
                //     res = max(res , freq[j] - freq[i]);
                // }
            }
        }
        return res != INT_MIN?res:-1;
    }
};