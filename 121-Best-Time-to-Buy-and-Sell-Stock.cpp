class Solution {
public:
    int maxProfit(vector<int>& p) {
        int i,j,x=INT_MAX,y=0;
        for(i=0;i<p.size();i++){
            x=min(x,p[i]);
            y=max(y,p[i]-x);
        }
        return y>0 ? y : 0;
    }
};