/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isEqual(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if ((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val))
            return false;
        return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // Look for a node whose value is equal to subRoot->val then apply is Equal function
        if (!root)
            return false;
        bool res1 = false;
        if (root->val == subRoot->val)
            res1 = isEqual(root, subRoot);
        return res1 || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};