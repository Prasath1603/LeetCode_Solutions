class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0, currentSum = 0;
        prefixSumCount[0] = 1;
        for (int i : nums) {
            currentSum += i;

            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            prefixSumCount[currentSum]++;
        }
        return count;
    }
};