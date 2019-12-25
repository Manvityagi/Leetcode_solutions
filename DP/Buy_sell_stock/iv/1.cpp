#define ll long long
class Solution
{
public:
    int quickSolve(vector<int> prices)
    {
        int len = prices.size(), profit = 0;
        for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {

        ll n = prices.size();
        if (n == 0)
            return 0;
        if (k >= n / 2)
            return quickSolve(prices);

        vector<vector<ll>> dp(k + 1, vector<ll>(n));

        for (ll K = 1; K <= k; K++)
        {
            ll minprice = prices[0];
            for (ll i = 1; i < n; i++)
            {
                minprice = min(minprice, prices[i] - dp[K - 1][i - 1]);
                dp[K][i] = max(dp[K][i - 1], prices[i] - minprice);
            }
        }
        return dp[k][n - 1];
    }
};