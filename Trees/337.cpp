/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define LL long long
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int helper(vector<LL> vec, int choice)
    {
        if (choice >= vec.size())
            return 0;

        if (vec.size() == 0)
            return 0;

        //choice += 2
        //op1 - choose choice to sum

        return max(vec[choice] + helper(vec, choice + 2), helper(vec, choice + 2));

        //op2 - dont choose choice to

        //return max(op1,op2)
    }

    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!(root->left) && !(root->right))
            return root->val;

        int depth = height(root);

        vector<LL> sumOfLevels(depth + 1);
        sumOfLevels[1] = root->val;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int r = 2;

        while (!q.empty())
        {
            TreeNode *top = q.front();
            q.pop();
            if (top == NULL)
            {
                r++;
                if (q.size() >= 1)
                    q.push(NULL);
                continue;
            }

            if (top->left)
            {
                // cout << r << " " << top->left->val << endl;
                q.push(top->left);
                sumOfLevels[r] += top->left->val;
            }

            if (top->right)
            {
                // cout << r << " " << top->right->val << endl;
                q.push(top->right);
                sumOfLevels[r] += top->right->val;
            }
        }
        return helper(sumOfLevels, 1);
        // return max(helper(sumOfLevels,1),helper(sumOfLevels,2));
    }
};