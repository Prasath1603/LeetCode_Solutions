class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end(),0);
        int prefixSum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(prefixSum == (total - prefixSum - nums[i])){
                return i;
            }
            prefixSum += nums[i];
        }
        return  -1;
    }
};