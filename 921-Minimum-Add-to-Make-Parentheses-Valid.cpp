class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char i : s){
            if(!st.empty()){
                char t = st.top();
                if(t == '(' && i == ')') st.pop();
                else st.push(i);
            }
            else st.push(i);
        }
        return st.size();
    }
};