class Solution
{
public:
    // A graph is bipartite if it can be colored completely with the help of atmost 2 colors
    // Given that no two adjacent nodes havethe same color
    bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &colorNode)
    {
        colorNode[node] = color;

        for (auto adjNode : graph[node])
        {
            if (colorNode[adjNode] == -1)
            {
                if (!dfs(adjNode, !color, graph, colorNode))
                    return false;
            }
            else if (colorNode[adjNode] == colorNode[node])
                return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int noOfNodes = graph.size(), color = 0;
        vector<int> colourNode(noOfNodes, -1);

        for (int i = 0; i < noOfNodes; i++)
        {
            if (colourNode[i] == -1)
            {
                if (!dfs(i, color, graph, colourNode))
                    return false;
            }
        }

        return true;
    }
};