class Solution {
public:
    int countElements(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int m = 0, n = 0;
            for(int j = 0 ; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    n = 1;
                }
                else if(nums[j] < nums[i]){
                    m = 1;
                }
            }
            if( m == 1 && n == 1) count++;
        }
        return count;
    }
};