class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {time, server}
        vector<bool> available(k, true); // O(1) availability check
        set<int> available2; // Keeps track of free servers for upper_bound search
        
        for (int i = 0; i < k; ++i) {
            available2.insert(i);
        }

        vector<int> result(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];
            int neededServer = i % k;

            // Free up servers whose tasks are completed by the current arrival time
            while (!pq.empty() && pq.top().first <= time) {
                auto [t, server] = pq.top();
                pq.pop();
                available[server] = true;
                available2.insert(server);
            }

            if (available2.empty()) {
                continue; // All servers are busy, drop request
            }

            int loadt = load[i];
            int assignedServer = -1;

            if (available[neededServer]) {
                assignedServer = neededServer;
            } else {
                auto it1 = available2.upper_bound(neededServer);
                if (it1 != available2.end()) {
                    assignedServer = *it1;
                } else {
                    assignedServer = *available2.begin(); // Wrap around
                }
            }

            // Allocate the server
            available[assignedServer] = false;
            available2.erase(assignedServer);
            result[assignedServer]++;
            pq.push({time + loadt, assignedServer});
        }

        int max_val = *max_element(result.begin(), result.end());
        vector<int> max_indices;

        for (int i = 0; i < result.size(); ++i) {
            if (result[i] == max_val) {
                max_indices.push_back(i);
            }
        }
        
        return max_indices;
    }
};