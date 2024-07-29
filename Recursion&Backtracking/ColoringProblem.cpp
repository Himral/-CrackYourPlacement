bool isValidColor(int node, int colorNode, vector<vector<int>> &adjList, vector<int> &color)
{
    for (auto adjNode : adjList[node])
    {
        if (color[adjNode] != -1 && color[adjNode] == colorNode)
        {
            return false;
        }
    }
    return true;
}
bool dfs(int node, int m, int n, vector<vector<int>> &adjList, vector<int> &color)
{
    if (node == n)
        return true;

    for (int i = 0; i < m; i++)
    {
        if (color[node] == -1)
        {
            if (isValidColor(node, i, adjList, color))
            {
                color[node] = i;
                if (dfs(node + 1, m, n, adjList, color))
                    return true;
                color[node] = -1;
            }
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<vector<int>> adjList(n);
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    return dfs(0, m, n, adjList, color);
}