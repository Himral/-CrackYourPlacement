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
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        DisjointSet ds(n + 1);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            int parentU = ds.findUParent(u), parentV = ds.findUParent(v);
            if (parentU == parentV)
            {
                return edges[i];
            }
            ds.unionByRank(u, v);
        }

        return {};
    }
};