class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int nested = 0;

        for(char ch : s) {
            if(ch == '(') {
                nested++;
                ans = max(ans, nested);
            }

            if(ch == ')') nested--;
        }

        return ans;
    }
};