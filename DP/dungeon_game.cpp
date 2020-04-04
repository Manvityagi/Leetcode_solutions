#define LL long long
#define ppl pair<LL, LL>

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &A)
    {
        int r = A.size();
        if (r == 0)
            return 0;
        int c = A[0].size();

        vector<vector<pair<LL, LL>>> dp(r + 1, vector<pair<LL, LL>>(c + 1));
        if (A[0][0] <= 0)
        {
            dp[0][0].first = 1 - A[0][0];
            dp[0][0].second = 1;
        }
        else
        {
            dp[0][0].first = 0;
            dp[0][0].second = A[0][0];
        }

        //first row
        for (int j = 1; j < c; j++)
        {
            if (A[0][j] + dp[0][j - 1].second > 0)
            {
                dp[0][j].first = dp[0][j - 1].first;
                dp[0][j].second = dp[0][j - 1].second + A[0][j];
            }
            else
            {
                int previ = 0, prevj = j - 1;
                dp[0][j].first = dp[previ][prevj].first + 1 - dp[previ][prevj].second - A[0][j];
                dp[0][j].second = 1;
            }
        }

        //first col
        for (int i = 1; i < r; i++)
        {
            if (A[i][0] + dp[i - 1][0].second > 0)
            {
                dp[i][0].first = dp[i - 1][0].first;
                dp[i][0].second = dp[i - 1][0].second + A[i][0];
            }
            else
            {
                int previ = i - 1, prevj = 0;
                dp[i][0].first = dp[previ][prevj].first + 1 - dp[previ][prevj].second - A[i][0];
                dp[i][0].second = 1;
            }
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {

                if (A[i][j] + dp[i][j - 1].second > 0 && A[i][j] + dp[i - 1][j].second > 0)
                {
                    //jiska first chota hai

                    int previ, prevj;
                    if (dp[i][j - 1].first < dp[i - 1][j].first)
                    {
                        previ = i;
                        prevj = j - 1;
                    }
                    else
                    {
                        previ = i - 1;
                        prevj = j;
                    }

                    dp[i][j].first = dp[previ][prevj].first;
                    dp[i][j].second = dp[previ][prevj].second + A[i][j];
                }
                else if (A[i][j] + dp[i][j - 1].second > 0 && A[i][j] + dp[i - 1][j].second > 0)
                {

                    int previ, prevj;
                    if (dp[i][j - 1].first < dp[i - 1][j].first)
                    {
                        previ = i;
                        prevj = j - 1;
                    }
                    else
                    {
                        previ = i - 1;
                        prevj = j;
                    }

                    dp[i][j].first = dp[previ][prevj].first + 1 - dp[previ][prevj].second - A[i][j];
                    dp[i][j].second = 1;
                }
                else
                {
                    if (dp[i][j - 1].first < dp[i - 1][j].first)
                    {
                        dp[i][j].first = dp[i][j - 1].first;
                        dp[i][j].second = dp[i][j - 1].second + A[i][j];
                    }
                    else
                    {
                        dp[i][j].first = dp[i - 1][j].first;
                        dp[i][j].second = dp[i - 1][j].second + A[i][j];
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << dp[i][j].first << ":" << dp[i][j].second << "  ";
            }
            cout << endl;
        }

        return dp[r - 1][c - 1].first;
    }
};