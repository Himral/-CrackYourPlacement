class DisjointSet
{

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;
        set<int> cells;
        for (int i = 0; i < stones.size(); i++)
        {
            int u = stones[i][0], v = stones[i][1];
            maxRow = max(maxRow, u);
            maxCol = max(maxCol, v);
        }
        maxRow++, maxCol++;
        DisjointSet ds(maxRow + maxCol);

        for (int i = 0; i < stones.size(); i++)
        {
            int u = stones[i][0], v = stones[i][1];
            int row = u, col = v + maxRow;
            cells.insert(row);
            cells.insert(col);
            int parentR = ds.findUPar(row), parentC = ds.findUPar(col);

            if (parentR == parentC)
                continue;
            ds.unionByRank(parentR, parentC);
        }

        int noOfComponents = 0;
        for (int i = 0; i < maxRow + maxCol; i++)
        {
            if (cells.find(i) != cells.end() && ds.findUPar(i) == i)
                noOfComponents++;
        }
        // cout << noOfComponents << "\n";
        return stones.size() - noOfComponents;
    }
};