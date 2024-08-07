class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int i;
        int n = a.size();
        vector<int> v;
        vector<int> p;
        vector<int> s;
        int x = 1;
        for (i = 0; i < n; i++) {
            p.push_back(x * a[i]);
            x *= a[i];
        }
        x = 1;
        for (i = n - 1; i > -1; i--) {
            s.push_back(x * a[i]);
            x *= a[i];
        }
        reverse(s.begin(), s.end());
        for (i = 1; i < n - 1; i++) {
            a[i] = (p[i - 1] * s[i + 1]);
        }
        a[0] = s[1];
        a[n - 1] = p[n - 2];
        return a;
    }
};