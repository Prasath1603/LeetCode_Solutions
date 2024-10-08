class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), left = 0 , right = n - 1 , res = 0;
        while( left < right){
            res = max( res , (right - left) * min(height[left],height[right]));
            if(height[left] < height[right]) left++;
            else right --;
        }return res;
    }
};