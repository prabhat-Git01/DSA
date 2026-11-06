
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Step 1: Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Step 2: Store queries with original indices
        vector<pair<int, int>> sortedQueries;

        for(int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        // Step 3: Initialize sliding window
        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        int left = 0;
        int right = 0;
        int activeServers = 0;

        // Step 4: Process queries in sorted order
        for(auto [q, idx] : sortedQueries) {

            int lower = q - x;
            int upper = q;

            // Add logs whose timestamp <= upper
            while(right < logs.size() &&
                  logs[right][1] <= upper) {

                int id = logs[right][0];

                if(freq[id] == 0) {
                    activeServers++;
                }

                freq[id]++;
                right++;
            }

            // Remove logs whose timestamp < lower
            while(left < right &&
                  logs[left][1] < lower) {

                int id = logs[left][0];

                freq[id]--;

                if(freq[id] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Servers with zero requests
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};
