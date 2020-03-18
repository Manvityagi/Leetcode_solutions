/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int helper(TreeNode *root, int currdepth, string drn)
    {
        if (!root)
            return 0;

        int op1, op2;
        if (drn == "left")
        {
            op1 = helper(root->right, currdepth + 1, "right");
            op2 = helper(root->left, 0, "left");
        }
        else
        {
            op1 = helper(root->left, currdepth + 1, "left");
            op2 = helper(root->right, 0, "right");
        }

        return 1 + max(op1, op2);
    }

    int longestZigZag(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftans = helper(root->left, 0, "left");
        int rightans = helper(root->right, 0, "right");

        return max(leftans, rightans);
    }
};