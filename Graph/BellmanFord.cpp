// Bellmand Ford is a single source path finding algorithm
// for finding the shortest distance of a source to all paths
//Time Complexity : O(N * n-1)
//Space Complexity : O(N)
vector<int> bellman_ford(int N, vector<vector<int>> &edges, int S)
{
    vector<int> dist(N, 1e8);

    dist[S] = 0;
    // N-1 relaxations
    for (int i = 0; i < N; i++)
    {
        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    // Nth relaxation
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            return {-1};
    }
    return dist;
}