// TC : O(N^2)
// SC : O(N^2)
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
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), maxSize = 0;
        DisjointSet ds(n * n);

        vector<int> delRow = {0, -1, 0, 1}, delCol = {-1, 0, 1, 0};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int cellNo = i * n + j;
                    for (int k = 0; k < 4; k++)
                    {
                        int nRow = i + delRow[k], nCol = j + delCol[k];
                        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1)
                        {
                            int newCellNo = nRow * n + nCol;
                            int parentU = ds.findUPar(cellNo), parentV = ds.findUPar(newCellNo);
                            if (parentU != parentV)
                            {
                                ds.unionBySize(cellNo, newCellNo);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int cellNo = i * n + j, size = 1;
                    set<int> visitedParent;
                    for (int k = 0; k < 4; k++)
                    {
                        int nRow = i + delRow[k], nCol = j + delCol[k];
                        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1)
                        {
                            int newCellNo = nRow * n + nCol;
                            int parentU = ds.findUPar(newCellNo);
                            if (visitedParent.find(parentU) == visitedParent.end())
                            {
                                size += ds.size[parentU];
                                visitedParent.insert(parentU);
                            }
                        }
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }

        return (maxSize == 0) ? n * n : maxSize;
    }
};