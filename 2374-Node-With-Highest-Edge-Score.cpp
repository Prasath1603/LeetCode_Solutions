class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> scores(edges.size(), 0); 
        
      
        for (int i = 0; i < edges.size(); ++i) {
            scores[edges[i]] += i; 
        }
        
      
        long long maxScore = -1;
        int resultNode = 0;
        
        for (int i = 0; i < scores.size(); ++i) {
            if (scores[i] > maxScore) {
                maxScore = scores[i];
                resultNode = i;
            }
        }
        
        return resultNode;
    }
};
