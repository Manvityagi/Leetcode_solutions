class Solution {
public:
      int longestArithSeqLength(vector<int>& A) {
          int N = A.size();
        int pos[10001];
        memset(pos, -1, sizeof(pos));
        int dp[N][N];
        memset(dp, 0, sizeof(dp));
        int result = 0;
        pos[A[0]] = 0;
        for (int i = 1; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                int k = 2 * A[i] - A[j];
                if (k < 0 || k > 10000 || pos[k] == -1) continue;
                dp[i][j] = dp[pos[k]][i] + 1;
                result = max(result, dp[i][j]);
            }
            pos[A[i]] = i;
        }
        return result+2;
      }
};