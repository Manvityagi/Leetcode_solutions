#include<bits/stdc++.h>
class Solution {
public:
    const int inf = 1e7;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(target+1,inf)));
        
        //dp[i][j][k] = minimum cost to paint ith house with j color, making a total of k neigbhorhoods
        
        //base case => if i == 0 && k == 0 , dp[i][j][k] = 0
        for(int i = 0; i <= n; ++i)dp[0][i][0] = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= target; k++)
                {
                    //if the curr house is already colored, dp[i][j][k] = -1, (j != its color)
                    if(houses[i-1] && houses[i-1] != j) continue;
                    
                    if(!houses[i-1]) //ith house is not colored, and we are coloring it with jth color 
                    {
                        //here also we have 2 cases
                        
                        //(i-1)th house pe bhi agar j color tha, 
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k] + cost[i-1][j-1]);
                        
                        //(i-1)th house pe koi aur color hota other than j, 
                        for(int prev_color = 1; prev_color <= n; prev_color++)
                            if(prev_color != j)
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][prev_color][k-1] + cost[i-1][j-1]);
                    }
                    else //ith house is already colored with jth color
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                         for(int prev_color = 1; prev_color <= n; prev_color++)
                            if(prev_color != j)
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][prev_color][k-1]);
                    }
                }
            }
        }
        
        int res = inf;
        
        for(int color = 1; color <= n; color++){
            res = min(res,dp[m][color][target]);
        }
        
        return res == inf ? -1 : res;
    }
};