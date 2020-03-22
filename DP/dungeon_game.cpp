class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &A)
    {
        int r = A.size();
        if (r == 0)
            return 0;
        int c = A[0].size();

        vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));

        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j <= c; j++)
            {
            }
        }
    }
};