class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int unpaired = 0;

        for(char ch : s) {
            if(ch == '(') {
                st.push(ch);
                unpaired++;
            } else {
                if(st.size() > 0) {
                    unpaired--;
                    st.pop();
                } else {
                    unpaired++;
                }
            }
        }

        return unpaired;
    }
};