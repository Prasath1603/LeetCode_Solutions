class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while( j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < abs(target - res)){
                    res = sum;
                }
                if(sum > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};
