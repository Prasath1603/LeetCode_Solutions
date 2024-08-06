class Solution {
public:
    int minimumPushes(string word) {
        int f[26]={0};
        int i,n=word.size();
        for(i=0;i<n;i++){
            f[word[i]-'a']++;
        }
        int x=0,count=0,m=0;
        sort(rbegin(f),rend(f));
        for(i=0;i<26;i++){
            if(f[i]>0){
                count+=((m/8)+1)*f[i];
                m++;
            }
        }
        return count;
    }
};