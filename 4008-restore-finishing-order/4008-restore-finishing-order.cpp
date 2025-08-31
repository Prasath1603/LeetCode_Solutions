class Solution {
public:
    bool isFound(vector<int>& arr , int key){
        int l = 0 , r = arr.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(arr[m] == key) return 1;
            else if(arr[m] > key) r = m - 1;
            else l = m + 1;
        }
        return 0;
    }

    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        for(int i : order){
            if(isFound(friends , i)) res.push_back(i);
        }
        return res;
    }
};