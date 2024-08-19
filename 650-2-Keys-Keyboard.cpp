class Solution {
public:
    bool isPrime(int n){
        if(n==2)
        return true;
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int minSteps(int n) {
        int count=0;
        while(n>1){
            for(int i=2;i<1000;i++){
                if(isPrime(i)){
                    if(n%i==0){
                        count+=i;
                        n/=i;
                        break;
                    }
                }
            }
        }
        return count;
    }
};