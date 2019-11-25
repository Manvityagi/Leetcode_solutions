class Solution
{
public:
    bool isPal(string A, int s, int e)
    {
        while (s < e)
        {
            if (A[s] != A[e])
            {
                return false;
            }
            s++;
            e--;
        }

        return true;
    }
    int minCut(string A)
    {
        int len = A.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int gap = 0; gap < len; gap++)
        {
            for (int i = 0, j = i + gap; i < len; i++)
            {
                if (i == j)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (isPal(A, i, j))
                        dp[i][j] = 0;
                    else
                        dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        }

        return dp[0][len - 1];
    }
};



/////////////////////////////BETTER////////////////

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;       //act as a sentinel
        
        for(int i = 0; i < n; i++){
	//palindrome of length 1,3,5...
            for(int len = 0; i-len >= 0 && i+len < n && s[i-len] == s[i+len]; len++)
                dp[i+len+1] = min(dp[i+len+1], dp[i-len]+1);
	//palindrome of lenght 2,4,6...
            for(int len = 0; i-len >= 0 && i+len+1 < n && s[i-len] == s[i+len+1]; len++)
                dp[i+len+2] = min(dp[i+len+2], dp[i-len]+1);
        }
        return dp[n];
    }
};
