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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        auto iter = root->left;
        if (iter)
        {
            //Moving to the largest of left subtree to append to right of root
            while (iter->right)
            {
                iter = iter->right;
            }
            //Shifting process
            iter->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->right); //Recursive call to the new right subtree which was left of root previously
    }
};