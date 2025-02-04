//https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
public:
    vector<vector<int>> criticalEdges;
    vector<int> disc, low;
    int time = 0;

    void dfs(int u, int parent, vector<vector<int>> &graph) {
        disc[u] = low[u] = ++time;
        
        for (int v : graph[u]) {
            if (disc[v] == -1) {  // If v is not visited
                dfs(v, u, graph);
                low[u] = min(low[u], low[v]);

                // Check if (u, v) is a critical connection
                if (low[v] > disc[u]) {
                    criticalEdges.push_back({u, v});
                }
            } else if (v != parent) {  // Update low value if not a direct cycle
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);  // Directed graph
            graph[edge[1]].push_back(edge[0]);
        }

        disc.assign(n, -1);
        low.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, graph);
            }
        }
        
        return criticalEdges;
    }
};
