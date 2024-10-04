class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long sum = 0,total = 0,count = 0;
        for(int i : skill) sum += i;
        long long target = sum / (n/2);
        cout<<target;
        int i = 0, j = n - 1 ;
        while(i < j){
            long long x = skill[i] + skill[j];
            if(x == target){
                total += (skill[i] * skill[j]);
                count++;
                i++; j--;
            }
            else if(x < target){
                i++;
            }
            else{
                j--;
            }
        }
        if(i < j || i == j || count != (n/2)){
            return -1;
        }
        return total;
    }
};