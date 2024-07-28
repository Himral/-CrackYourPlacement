class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // We need to calculate the minimum steps taken
        vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
        vector<int> delRow = {-2, -1, 1, 2, -2, -1, 1, 2}, delCol = {-1, -2, -2, -1, 1, 2, 2, 1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {KnightPos[0] - 1, KnightPos[1] - 1}});
        dist[KnightPos[0] - 1][KnightPos[1] - 1] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int distanceToNode = it.first, r = it.second.first, c = it.second.second;
            if (r == TargetPos[0] - 1 && c == TargetPos[1] - 1)
                return distanceToNode;

            for (int i = 0; i < 8; i++)
            {
                int nRow = r + delRow[i], nCol = c + delCol[i];
                if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < N)
                {
                    if (distanceToNode + 1 < dist[nRow][nCol])
                    {
                        dist[nRow][nCol] = distanceToNode + 1;
                        if (nRow == TargetPos[0] - 1 && nCol == TargetPos[1] - 1)
                            return dist[nRow][nCol];
                        pq.push({dist[nRow][nCol], {nRow, nCol}});
                    }
                }
            }
        }

        return -1;
    }
};