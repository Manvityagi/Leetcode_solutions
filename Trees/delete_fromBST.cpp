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
    //3 cases
    //to be deleted - node with 0 children i.e,leaf node = directly delete
    //1 child = swap
    // 2 child = 2 options
    //1.replace with smallest elt of right subtree
    //2.replace with largest elt of left subtree

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (!search(root, key))
            return root;

        TreeNode *temp = root;

        if (key->val == temp->val)
        {
        }
        else if (key->val < temp->val)
        {
        }
        else if (key->val > temp->val)
    }
};