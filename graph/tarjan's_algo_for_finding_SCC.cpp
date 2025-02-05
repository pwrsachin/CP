#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> tarjansSCC(int n, vector<vector<int>>& adj) {
        vector<int> disc(n, -1);   // Discovery time of each node
        vector<int> low(n, -1);    // Lowest discovery time reachable
        vector<bool> inStack(n, false); // Track nodes in the current SCC
        stack<int> st;             // Stack for SCC tracking
        vector<vector<int>> sccs;  // Result: List of SCCs
        int time = 0;              // Global discovery time counter

        // DFS function using recursion
        function<void(int)> dfs = [&](int u) {
            disc[u] = low[u] = time++; // Initialize discovery time and low value
            st.push(u);
            inStack[u] = true;

            // Explore all neighbors
            for (int v : adj[u]) {
                if (disc[v] == -1) { // If v is not visited
                    dfs(v);
                    low[u] = min(low[u], low[v]); // Update low[u] after backtracking
                } 
                // If v is in the stack, it's part of the current SCC
                else if (inStack[v]) {
                    low[u] = min(low[u], disc[v]); // Update low[u] using back edge
                }
            }

            // If u is the root of an SCC
            if (low[u] == disc[u]) {
                vector<int> scc;
                while (st.top() != u) {
                    int v = st.top();
                    st.pop();
                    inStack[v] = false;
                    scc.push_back(v);
                }
                // Add the root to the SCC
                st.pop();
                inStack[u] = false;
                scc.push_back(u);
                sccs.push_back(scc);
            }
        };

        // Perform DFS for all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }

        return sccs;
    }
};

int main() {
    Solution sol;
    int n = 8;
    vector<vector<int>> adj = {
        {1},        // 0 -> 1
        {2},        // 1 -> 2
        {0, 3},     // 2 -> 0, 2 -> 3
        {4},        // 3 -> 4
        {5},        // 4 -> 5
        {3, 6},     // 5 -> 3, 5 -> 6
        {7},        // 6 -> 7
        {6}         // 7 -> 6
    };

    vector<vector<int>> sccs = sol.tarjansSCC(n, adj);

    cout << "Strongly Connected Components:\n";
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
