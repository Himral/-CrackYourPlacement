//Time Complexity : O(N)=> To construct adjacency List + O(N) => Queue Traverse
//Space Complexity : O(N)=> inDegree Array + O(N)=> queue
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses, 0), ans;

        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            inDegree[u]++;
            adjList[v].push_back(u);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto adjNode : adjList[node])
            {
                inDegree[adjNode]--;
                if (inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        cout << ans.size() << " ";
        if (ans.size() == numCourses)
            return true;
        return false;
    }
};