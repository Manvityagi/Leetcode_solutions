class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = i + gap; i < n, j < n; i++, j++)
            {
                // cout << i << " " << j << endl;
                //finding dp[i][j] - minimum of all the partitions
                if (j == i)
                {
                    dp[i][j] = stones[i];
                }
                else if (j - i == 1)
                {
                    dp[i][j] = abs(stones[i] - stones[j]);
                }
                else
                {
                    // cout << "hell";
                    for (int k = i; k < j; k++)
                    {
                        if (i == 0 && j == 2)
                        {
                            cout << dp[i][j] << endl;
                            cout << i << " " << k << " i:k " << dp[i][k] << endl;
                            cout << k + 1 << " " << j << " k:j " << dp[k + 1][j] << endl;
                        }
                        dp[i][j] = min(dp[i][j], abs(dp[i][k] - dp[k + 1][j]));
                    }
                }
            }
        }

        //         for(int i = 0; i < n; i++){
        //             for(int j = 0; j < n; j++){
        //                 if(dp[i][j] != INT_MAX)
        //                 cout << dp[i][j] << " ";
        //                 else
        //                     cout << -1 << " ";
        //             }
        //             cout << endl;
        //         }

        return dp[0][n - 1];
    }
};