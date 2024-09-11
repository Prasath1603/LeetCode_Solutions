class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zcount=0,ocount=0,tcount=0;
        for(int i:nums){
            if(i==0) zcount++;
            else if(i==1) ocount++;
            else tcount++;
        }
        vector<int>v;
        int i;
        for(i=0;i<zcount;i++)
        v.push_back(0);
        for(i=0;i<ocount;i++)
        v.push_back(1);
        for(i=0;i<tcount;i++)
        v.push_back(2);
        for(i=0;i<nums.size();i++)
        nums[i]=v[i];
    }
};