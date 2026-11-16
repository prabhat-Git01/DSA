class Solution {
public:
    // int sum(string s) {
    //     int count = 0;
    //     for(char ch : s) {
    //         count += ch - '0';
    //     }
    //     return count;
    // }

    string digitSum(string s, int k) {
        string s1 = s;

        while(s1.length() > k) {
            string ans = "";
            vector<string> groups;

            // Step 1
            for(int i=0; i<s1.length(); i+=k) {
                groups.push_back(s1.substr(i,k));
            }

            for(int i=0; i<groups.size(); i++) {
                int sod = 0;
                for(char ch : groups[i]) {
                    sod += ch - '0';
                }

                groups[i] = to_string(sod);
                ans += groups[i];
            }

            // // Step 2
            // for(string &s : groups) {
            //     int sod = sum(s);
            //     s = to_string(sod);
            // }

            // // Step 3
            // for(int i=0; i<groups.size(); i++) {
            //     ans += groups[i];
            // }

            s1 = ans;
        }

        return s1;
    }
};