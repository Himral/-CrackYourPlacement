//We have used a simple dfs approach to find all the possible paths to reach the n-1,n-1 cell from (0,0) cell
//TC : O(N + N)
//SC : O(N^2) + O(1)
class Solution
{
public:
    bool isValid(int nRow, int nCol, vector<vector<int>> &mat, vector<vector<int>> &vis)
    {
        if (nRow >= 0 && nRow < mat.size() && nCol >= 0 && nCol < mat.size() && mat[nRow][nCol] == 1 && !vis[nRow][nCol])
            return true;
        return false;
    }
    void dfs(int row, int col, vector<vector<int>> &mat, unordered_map<char, pair<int, int>> &directions, vector<vector<int>> &vis, vector<string> &ans, string &str)
    {
        if (row == mat.size() - 1 && col == mat.size() - 1)
            ans.push_back(str);

        for (auto itr : directions)
        {
            char ch = itr.first;
            int delRow = itr.second.first, delCol = itr.second.second;
            int nRow = row + delRow, nCol = col + delCol;
            if (isValid(nRow, nCol, mat, vis))
            {
                str += ch;
                vis[row][col] = 1;
                dfs(nRow, nCol, mat, directions, vis, ans, str);
                vis[row][col] = 0;
                str.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        vector<string> ans;
        // A rat can move Up , down , left and right
        // We need to find the total no of possible paths
        if (mat[0][0] == 0)
            return ans;

        string str = "";

        unordered_map<char, pair<int, int>> directions;
        directions['D'] = {1, 0};
        directions['U'] = {-1, 0};
        directions['L'] = {0, -1};
        directions['R'] = {0, 1};

        vector<vector<int>> vis(mat.size(), vector<int>(mat.size(), 0));

        dfs(0, 0, mat, directions, vis, ans, str);

        return ans;
    }
};