/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Time Complexity : O(N) + O(N*E)
// Space Complexity : O(N)->for the unordered map + O(N)->for the recursive stack space
class Solution
{
public:
    void cloneGraphRec(Node *node, unordered_map<Node *, Node *> &mapNodes)
    {
        if (mapNodes.find(node) != mapNodes.end())
            return;

        Node *newNode = new Node(node->val);
        mapNodes[node] = newNode;

        for (auto adj : node->neighbors)
        {
            if (mapNodes.find(adj) == mapNodes.end())
                cloneGraphRec(adj, mapNodes);
        }
    }
    void markNeighborsOfNode(Node *node, vector<int> &vis, unordered_map<Node *, Node *> &mapNodes)
    {
        Node *newNode = mapNodes[node];
        vis[node->val] = 1;

        for (auto adj : node->neighbors)
        {
            newNode->neighbors.push_back(mapNodes[adj]);
            if (!vis[adj->val])
            {
                markNeighborsOfNode(adj, vis, mapNodes);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        unordered_map<Node *, Node *> mapNodes;

        cloneGraphRec(node, mapNodes);

        vector<int> vis(mapNodes.size() + 1, 0);

        // Mark neighbors of the new nodes
        markNeighborsOfNode(node, vis, mapNodes);

        return mapNodes[node];
    }
};