class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int i = 0 , j = s.size() - 1;
        while( i < j && i < s.size() && j >= 0){
            while(i < j && s[i] != '1') i++;
            while(i < j &&s[j] != '0') j--;
            swap += j - i;
            i++; j--;
        }
        return swap;
    }
};