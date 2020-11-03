class Solution {
public:


    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>sets(101, 0);
        queue<int>q;
        vector<bool>visited(101, false);
        int count = 0;
        visited[0] = true;
        sets[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto n : graph[node]) {
                if (visited[n] == true) {
                    if (sets[node] == sets[n])
                        return false;
                    continue;
                }
                visited[n] = true;
                sets[node] == 1 ? sets[n] = 2 : sets[n] = 1;
                q.push(n);
                count++;
            }
            if (q.empty() && count != graph.size()) {
                int y = 1;
                while (node + y < graph.size()) {
                    if (visited[node + y] == false) {
                        q.push(node + y);
                        node = node + y;
                        break;
                    }
                    y++;
                }

            }

        }
        return true;

    }

};