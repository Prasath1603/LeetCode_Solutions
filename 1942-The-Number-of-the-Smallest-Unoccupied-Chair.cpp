class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used_chairs;

        priority_queue<int, vector<int>, greater<int>> available_chairs;

        for (int i = 0; i < n; i++) {
            available_chairs.push(i);
        }


        vector<vector<int>> temp = times;
        for (int i = 0; i < n; i++) {
            temp[i].push_back(i);
        }


        sort(temp.begin(), temp.end());


        for (int i = 0; i < n; i++) {
            int arrival = temp[i][0];
            int leave = temp[i][1];
            int index = temp[i][2];


            while (!used_chairs.empty() && used_chairs.top().first <= arrival) {
                available_chairs.push(used_chairs.top().second);
                used_chairs.pop();
            }

            int chair = available_chairs.top();
            available_chairs.pop();


            if (index == targetFriend) {
                return chair;
            }


            used_chairs.push({leave, chair});
        }

        return -1;
    }
};
