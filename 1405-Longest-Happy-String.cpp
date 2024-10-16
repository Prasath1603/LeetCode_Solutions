
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string t = "";
        while (!pq.empty()) {

            auto [val, ch] = pq.top();
            pq.pop();

            if (t.size() >= 2 && t[t.size() - 1] == ch &&
                t[t.size() - 2] == ch) {
                if (pq.empty())
                    break; 

                auto [val2, ch2] = pq.top();
                pq.pop();

                t += ch2;
                if (--val2 > 0)
                    pq.push({val2, ch2});

                pq.push({val, ch});
            } else {
                t += ch;
                if (--val > 0)
                    pq.push({val, ch});
            }
        }
        return t;
    }
};