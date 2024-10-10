class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int width = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                st.push(i);
            }
        }
        for(int j = nums.size() - 1; j > -1 ; j--){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                width = max(width, j - st.top());
                st.pop();
            }
        }
        return width;
    }
};