class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            res = min( res , digitSum(nums[i]));
        }
        return res;
    }
};