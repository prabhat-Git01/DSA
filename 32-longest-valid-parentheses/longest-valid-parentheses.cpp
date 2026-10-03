class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        
        // Scan from left to right
        int open = 0, close = 0;
        for(char el : s) {
            if(el == '(') open++;
            else close++;

            if(open == close) {
                ans = max(ans, 2 * close);
            } else if(close > open) {
                open = 0, close = 0;
            }
        }

        // Scan from right to left
        open = 0, close = 0;

        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                ans = max(ans, 2 * open);
            } else if(open > close) {
                open = 0, close = 0;
            }
        }

        return ans;
    }
};