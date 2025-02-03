class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() , a = 1, b = 1 , c = 1 , d = 1;
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] < nums[i + 1]) a++;
            else{
                c = max(c , a);
                a = 1;
            }
        }
        c = max(c , a);
        for(int j = 0 ; j < n - 1 ; j++){
            if(nums[j] > nums[j + 1]) b++;
            else{
                d = max(d , b);
                b = 1;
            }
        }
        d = max(d , b);
        // cout<<a<<" "<<b<<" "<<c<<" "<<d;
        return max(c , d);
    }
};