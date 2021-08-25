#include <bits/stdc++.h>
using namespace std;
//Detect cycle in undirected graph using BFS

class Solution
{
public:
    bool isCycle(int S, vector<int> adj[], vector<bool> &visited)
    {
        visited[S] = true;
        queue<pair<int, int>> q;
        q.push({S, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int p = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else
                {
                    if (p != it)
                        return true;
                }
            }
        }

        return false;
    }

    bool checkCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V + 1, false);
        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                if (isCycle(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    int u, v;
    vector<int> adj[V + 1];

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //  checkCycle(V,adj);
}