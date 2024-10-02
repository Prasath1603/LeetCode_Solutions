class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> unique(arr.begin(),arr.end());
        int i = 1;
        for(int j : unique){
            mp[j]=i;
            i++;
        }
        vector<int> res;
        for(int j : arr){
            res.push_back(mp[j]);
        }
        return res;
    }
};