class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int r = triangle.size();
        vector<vector<int>> dp(r);
        dp[0].push_back(triangle[0][0]);

        int ans = INT_MAX;

        for (int i = r - 1; i >= 0; i--)
        {
            int c = triangle[i].size();
            dp[i].push_back(vector<int>(c));

            for (int j = 0; j < c; j++)
            {
                if (i == r - 1)
                {
                    dp[i][j] = triangle[i][j];
                }
                else
                {
                    int op1 = j + 1 < c ? dp[i + 1][j + 1] : INT_MAX;
                    int op2 = dp[i + 1][j];
                    dp[i][j] = triangle[i][j] + min(op1, op2);
                }

                if (i == 0)
                {
                    ans = min(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};