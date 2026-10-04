class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int open = 0;
        for(char &ch : s){
            if(ch == '(' || ch == '*') open++;
            else open--;

            if(open < 0) return false;
        }

        int close = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ')' || s[i] == '*') close++;
            else close--;

            if(close < 0) return false;
        }

        return true;
    }
};