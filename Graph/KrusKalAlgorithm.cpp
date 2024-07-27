class DisjointSet
{
public:
    vector<int> rank, parent;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parentU = findUParent(u), parentV = findUParent(v);
        if (parentU == parentV)
            return;

        if (rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }
        else if (rank[parentU] == rank[parentV])
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
        else
        {
            parent[parentU] = parentV;
        }
    }
};
static bool comparator(const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2)
{
    return p1.first < p2.first;
}

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUParent(u) != ds.findUParent(v))
            {
                // cout << "u : " << u << " v : " << v << "\n";

                mstWt += wt;
                // cout << "mst : " << mstWt << "\n";
                ds.unionByRank(u, v);
            }
        }

        return mstWt;
    }
};