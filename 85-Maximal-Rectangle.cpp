class Solution {
public:
    vector<int> Nse(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> v(n, n);
        for (int i = n - 1; i > -1; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty())
                v[i] = st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> Pse(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> v(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty())
                v[i] = st.top();
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = Nse(heights, heights.size());
        vector<int> pse = Pse(heights, heights.size());
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            area = max(area, heights[i] * (nse[i] - pse[i] - 1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = grid[i - 1][j] + 1;
                    }
                }
            }
        }
        int area = 0;
        for (auto& i : grid) {
            area = max(area , largestRectangleArea(i));
        }
        return area;
    }
};