// To effectively detect cycle in our graph we can use toposort algorithm
// If the size of our topological ordering is equal to V then no cycle is present
// Else cycle is there
//TC : O(N)
//SC : O(N) + O(N)
bool isCyclic(int V, vector<int> adj[])
{
    // In the adjacency list adj, element adj[i][j] represents an edge from i to j.
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i, v = adj[i][j];
            inDegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoSort;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for (auto adjNode : adj[node])
        {
            inDegree[adjNode]--;
            if (inDegree[adjNode] == 0)
                q.push(adjNode);
        }
    }

    if (topoSort.size() == V)
        return false;
    return true;
}