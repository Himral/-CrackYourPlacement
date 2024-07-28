
class Solution
{
public:
    vector<int> delRow = {0, -1, 0, 1}, delCol = {-1, 0, 1, 0};

    void dfs(int r, int c, vector<vector<int>> &grid, queue<pair<int, int>> &q)
    {
        int n = grid.size();
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1)
            return;

        grid[r][c] = 2; // Mark the cell as visited
        q.push({r, c});
        for (int i = 0; i < 4; i++)
        {
            int nRow = r + delRow[i], nCol = c + delCol[i];
            dfs(nRow, nCol, grid, q);
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;

        // Step 1: Mark the first island and push its coordinates into the queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid, q);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        // Step 2: Expand from the first island using BFS
        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nRow = r + delRow[i], nCol = c + delCol[i];
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n)
                    {
                        if (grid[nRow][nCol] == 1)
                        {
                            return steps;
                        }
                        else if (grid[nRow][nCol] == 0)
                        {
                            grid[nRow][nCol] = 2;
                            q.push({nRow, nCol});
                        }
                    }
                }
            }
            steps++;
        }

        return -1; // If no bridge is found (should not happen as per problem constraints)
    }
};
