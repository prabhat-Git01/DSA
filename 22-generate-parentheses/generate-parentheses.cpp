class Solution {
public:
    void dfs(vector<string>& res, string& s, int openingBrac, int closingBrac) {
        if(openingBrac == 0 && closingBrac == 0) {
            res.push_back(s);
            return;
        }

        if(openingBrac > 0) {
            s.push_back('(');
            dfs(res, s, openingBrac-1, closingBrac);
            s.pop_back();
        }

        if(closingBrac > openingBrac) {
            s.push_back(')');
            dfs(res, s, openingBrac, closingBrac-1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};

        string s = "";
        int openingBrac = n, closingBrac = n;
        vector<string> res;

        dfs(res, s, openingBrac, closingBrac);

        return res;
    }
};