class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(int i:chalk){
            sum+=i;
        }
        k=k%sum;
        while(k!=0){
            for(int i=0;i<chalk.size();i++){
                if(k<chalk[i]){
                    return i;
                }
                k-=chalk[i];
            }
        }
        return 0;
    }
};