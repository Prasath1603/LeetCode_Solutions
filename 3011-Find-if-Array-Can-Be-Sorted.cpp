class Solution {
public:
    int setbit(int n) {return __builtin_popcount(n);}
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool swapped;
        do{
            swapped = false;
            for(int i = 0; i < n - 1 ; i++){
                if(setbit(nums[i]) == setbit(nums[i + 1]) && nums[i] > nums[i + 1]){
                    swap(nums[i] , nums[i + 1]);
                    swapped = true;
                }
            }
        }while(swapped);
        // for(int i : nums) cout<<i<<" ";
        return is_sorted(nums.begin() , nums.end());

    }
};