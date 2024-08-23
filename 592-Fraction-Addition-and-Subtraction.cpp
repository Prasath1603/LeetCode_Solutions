#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int lcm(vector<int>& v) {
        int result = v[0];
        for (int i = 1; i < v.size(); i++) {
            result = lcm(result, v[i]);
        }
        return result;
    }

    vector<int> convert(const vector<string>& strVec) {
        vector<int> intVec;
        for (const string& str : strVec) {
            intVec.push_back(stoi(str));
        }
        return intVec;
    }

    string fractionAddition(string exp) {
        vector<int> numerators, denominators;
        int n = exp.size();
        int i = 0;

        while (i < n) {
           
            int sign = 1;
            if (exp[i] == '-' || exp[i] == '+') {
                sign = exp[i] == '-' ? -1 : 1;
                i++;
            }
            int numerator = 0;
            while (i < n && isdigit(exp[i])) {
                numerator = numerator * 10 + (exp[i] - '0');
                i++;
            }
            numerators.push_back(sign * numerator);

         
            i++;

            int denominator = 0;
            while (i < n && isdigit(exp[i])) {
                denominator = denominator * 10 + (exp[i] - '0');
                i++;
            }
            denominators.push_back(denominator);
        }

        int l = lcm(denominators);
        int numerator = 0;

        for (int i = 0; i < numerators.size(); i++) {
            numerator += numerators[i] * (l / denominators[i]);
        }

        int g = gcd(abs(numerator), l);
        string result = to_string(numerator / g) + "/" + to_string(l / g);

        return result;
    }
};

