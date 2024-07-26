class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adjList[], int S)
    {

        // PQ : dist,node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        pq.push({0, S});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int distToNode = it.first;
            int node = it.second;

            for (auto itr : adjList[node])
            {
                int v = itr[0];
                int wt = itr[1];

                if (distToNode + wt < dist[v])
                {
                    dist[v] = distToNode + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};