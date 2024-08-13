class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, int start,
                          vector<int>& currentCombination,
                          vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size() && target >= candidates[i];
             ++i) {

            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            currentCombination.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], i + 1,
                             currentCombination, result);
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;

        sort(candidates.begin(), candidates.end());

        findCombinations(candidates, target, 0, currentCombination, result);
        return result;
    }
};