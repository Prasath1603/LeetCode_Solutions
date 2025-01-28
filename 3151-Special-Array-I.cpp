class Solution {
public:
    bool isOdd(int x){ return x & 1;}
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if((isOdd(nums[i]) && isOdd(nums[i + 1])) || (!isOdd(nums[i]) && !isOdd(nums[i + 1]))) return false;
        }
        return true;
    }
};