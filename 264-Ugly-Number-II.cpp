#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> seen;
        
        pq.push(1);
        seen.insert(1);
        
        vector<int> primes = {2, 3, 5};
        long uglyNumber = 1;
        
        for (int i = 0; i < n; ++i) {
            uglyNumber = pq.top();
            pq.pop();
            
            for (int prime : primes) {
                long newUgly = uglyNumber * prime;
                if (seen.find(newUgly) == seen.end()) {
                    pq.push(newUgly);
                    seen.insert(newUgly);
                }
            }
        }
        
        return static_cast<int>(uglyNumber);
    }
};
