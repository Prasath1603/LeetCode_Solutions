class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for(int i : nums){
            if(!(i & 1)) res |= i;
        }
        return res;
    }
};