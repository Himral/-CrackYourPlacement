//TC : O(N)
//SC : O(N)
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *l = root->left, *r = root->right;
        root->left = r;
        root->right = l;
        return root;
    }
};