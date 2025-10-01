class Solution {
public:
    int numWaterBottles(int n, int m) {
        int count = n;

        while(n >= m){
            int x = (n / m);
            count += x;
            n = (n / m) + (n % m);
        }

        return count;
    }
};