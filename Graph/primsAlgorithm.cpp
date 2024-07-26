int spanningTree(int V, vector<vector<int>> adj[])
{
    int sum = 0;
    vector<int> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    // Wt , node

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;

        for (auto itr : adj[node])
        {
            int adjNode = itr[0];
            int EdgeWt = itr[1];
            if (!vis[adjNode])
            {
                pq.push({EdgeWt, adjNode});
            }
        }
    }

    return sum;
}