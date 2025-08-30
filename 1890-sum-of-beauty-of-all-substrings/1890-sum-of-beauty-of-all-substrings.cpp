class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), sum = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26 , 0);
            for(int j = i ; j < n ; j++){
                freq[s[j] - 'a'] += 1;

                int a = 0 , b = INT_MAX;
                for(int i : freq){
                    if(i > 0){
                        a = max(a , i);
                        b = min(b , i);
                    }
                }
                sum += abs(a - b);
            }
        }

        return sum;
    }
};