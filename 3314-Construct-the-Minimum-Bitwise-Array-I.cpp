class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; i++){
            int target = nums[i], flag = 0;
            for(int j = 1 ; j < target ; j++){
                if( (j | (j + 1)) == target){
                    flag = 1;
                    res.push_back(j);
                    break;
                }
            }
            if(!flag) res.push_back(-1);
        }
        return res;
    }
};