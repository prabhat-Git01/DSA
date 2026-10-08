class Solution {
public:
    string removeOuterParentheses(string s) {
        int idx = 0;
        string str = "";
        stack<char> st;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            } else {
                if(!st.empty()) {
                    st.pop();
                }
            }

            if(st.empty()) {
                str += s.substr(idx+1, i-1-(idx+1)+1);
                idx = i+1;
            }
        }

        return str;
    }
};