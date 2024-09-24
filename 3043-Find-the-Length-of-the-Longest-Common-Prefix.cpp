class Solution {
public:
    void helper(unordered_map<int, int>& mp, vector<int>& arr, bool f) {
        for (int i : arr) {
            while (i) {
                if (!f) {
                    mp[i] = 1;
                } else {
                    if (mp[i]) {
                        mp[i] += 1;
                    }
                }
                i /= 10;
            }
        }
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        helper(mp, arr1, false);
        helper(mp, arr2, true);
        int M = 0;
        for (auto& i : mp) {
            if (i.second >= 2) {
                int s = (log10(i.first) + 1);
                M = max(s, M);
            }
        }
        return M;
    }
};