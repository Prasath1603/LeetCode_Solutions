class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        int minIndex = -1, maxIndex = -1;

        for (int i = 0; i < arrays.size(); i++) {
            int first = arrays[i][0];
            int last = arrays[i][arrays[i].size() - 1];

            if (first < minVal) {
                minVal = first;
                minIndex = i;
            }
            if (last > maxVal) {
                maxVal = last;
                maxIndex = i;
            }
        }

     
        if (minIndex != maxIndex) {
            return maxVal - minVal;
        }

     
        int secondMinVal = INT_MAX, secondMaxVal = INT_MIN;

        for (int i = 0; i < arrays.size(); i++) {
            if (i != minIndex) {
                secondMinVal = min(secondMinVal, arrays[i][0]);
            }
            if (i != maxIndex) {
                secondMaxVal =
                    max(secondMaxVal, arrays[i][arrays[i].size() - 1]);
            }
        }

        return max(maxVal - secondMinVal, secondMaxVal - minVal);
    }
};

// vector<int>v;
// int i,j,n=arrays.size();
// for(i=0;i<n;i++){
//     for(j=0;j<arrays[i].size();j++){
//         v.push_back(arrays[i][j]);
//     }
// }
// sort(v.begin(),v.end());
// for(int k:v){
//     cout<<k<<" ";
// }
// if(v[0]==0){
//     for(int k:v){
//         if(k!=0){
//             return abs(k-v[v.size()-1]);
//         }
//     }
// }
// return abs(v[0]-v[v.size()-1]);