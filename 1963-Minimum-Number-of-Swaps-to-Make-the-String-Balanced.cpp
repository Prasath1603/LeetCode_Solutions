class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        for(char i : s){
            if(i == '[') count++;
            if(i == ']' && count > 0){
                count--;
            }
        }
        return (count + 1) / 2;
    }
};