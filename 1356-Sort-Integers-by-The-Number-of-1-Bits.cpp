class Solution {
public:
    int count(int n){
        int count = 0;
        n = __builtin_popcount(n);
        return n;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        sort(arr.begin() , arr.end());
        for(int i : arr){
            v.push_back({i,count(i)});
        }

        sort(v.begin() , v.end() , [](const pair<int,int> &a, const pair<int,int> &b){
            if(a.second == b.second){
                return a.first < b.first ;
            }
            return a.second < b.second;
        });

        // for(auto & i : v) cout<<i.first<<" "<<i.second<<endl;
        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] = v[i].first;
        }
        return arr;
    }
};