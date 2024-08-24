#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    string nearestPalindromic(string s) {
        int len = s.length();

        if (s == "1")
            return "0";

        long long originalNum = stoll(s);

        string allNines(len - 1, '9');
        string candidateAllNines = allNines.empty() ? "0" : allNines;

        string allZeros(len - 1, '0');
        string candidateAllZeros = "1" + allZeros + "1";

        string prefix = s.substr(0, (len + 1) / 2);
        string palindrome1 = createPalindrome(prefix, len % 2 == 0);

        string palindrome2 = createPalindrome(to_string(stoll(prefix) + 1), len % 2 == 0);
        string palindrome3 = createPalindrome(to_string(stoll(prefix) - 1), len % 2 == 0);

        long long p1 = stoll(palindrome1);
        long long p2 = stoll(palindrome2);
        long long p3 = stoll(palindrome3);
        long long candidate1 = stoll(candidateAllNines);
        long long candidate2 = stoll(candidateAllZeros);

        long long nearest = p1;
        if (p1 == originalNum) nearest = p2;

        if (abs(p2 - originalNum) < abs(nearest - originalNum) || 
            (abs(p2 - originalNum) == abs(nearest - originalNum) && p2 < nearest)) {
            nearest = p2;
        }

        if (abs(p3 - originalNum) < abs(nearest - originalNum) || 
            (abs(p3 - originalNum) == abs(nearest - originalNum) && p3 < nearest)) {
            nearest = p3;
        }

        if (abs(candidate1 - originalNum) < abs(nearest - originalNum) || 
            (abs(candidate1 - originalNum) == abs(nearest - originalNum) && candidate1 < nearest)) {
            nearest = candidate1;
        }

        if (abs(candidate2 - originalNum) < abs(nearest - originalNum) || 
            (abs(candidate2 - originalNum) == abs(nearest - originalNum) && candidate2 < nearest)) {
            nearest = candidate2;
        }

        return to_string(nearest);
    }

private:
    string createPalindrome(string prefix, bool evenLength) {
        string palindrome = prefix;
        if (!evenLength) {
            prefix.pop_back();
        }
        reverse(prefix.begin(), prefix.end());
        palindrome += prefix;
        return palindrome;
    }
};
