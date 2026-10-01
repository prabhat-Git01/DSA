class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(int i=0; i<s.length(); i++) {
            // Opening characters
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                // Closing characters
                if(st.size() == 0) return false;

                if(st.top() == '(' && s[i] == ')' ||
                    st.top() == '[' && s[i] == ']' ||
                    st.top() == '{' && s[i] == '}') {

                        st.pop();

                    } else {
                        return false;
                    }
            }
        }
        return st.size() == 0;
    }
};