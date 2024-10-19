bool ran = false;
unordered_map<int, string> mp{{1, "0"}, {2, "011"}};

void invert(string& s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = s[i] == '1' ? '0' : '1';
}

void f(string s, int n) {
    if (ran)
        return;

    if (n > 20)
        return;
    invert(s);
    std::reverse(s.begin(), s.end());
    mp[n] = mp[n - 1] + "1" + s;

    f(mp[n], n + 1);

    ran = true;
}

class Solution {
public:
    
    char findKthBit(int n, int k) {
        f("011", 3);
        return mp[n][k - 1];
    }
};