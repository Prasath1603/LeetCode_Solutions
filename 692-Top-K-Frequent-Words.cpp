class Solution {
public:
    struct  cmp{
        bool operator()(pair<int,string>p1,pair<int,string>p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string i : words){
            mp[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> p;
        for(auto & i : mp){
            p.push({i.second,i.first});
        }
        vector<string> res;
        while(k--){
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};