class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for(int i=0; i<s.length(); i++) {
            if(i>0) {
                if(s[i] == 'V' && s[i-1] == 'I') {
                    ans = ans - 1 + 4;
                    continue;
                } else if(s[i] == 'X' && s[i-1] == 'I') {
                    ans = ans - 1 + 9;
                    continue;
                } else if(s[i] == 'L' && s[i-1] == 'X') {
                    ans = ans - 10 + 40;
                    continue;
                } else if(s[i] == 'C' && s[i-1] == 'X') {
                    ans = ans - 10 + 90;
                    continue;
                } else if(s[i] == 'D' && s[i-1] == 'C') {
                    ans = ans - 100 + 400;
                    continue;
                } else if(s[i] == 'M' && s[i-1] == 'C') {
                    ans = ans - 100 + 900;
                    continue;
                }
            }

            if(s[i] == 'I') ans += 1;
            else if(s[i] == 'V') ans += 5;
            else if(s[i] == 'X') ans += 10;
            else if(s[i] == 'L') ans += 50;
            else if(s[i] == 'C') ans += 100;
            else if(s[i] == 'D') ans += 500;
            else if(s[i] == 'M') ans += 1000;
        }

        return ans;
    }
};