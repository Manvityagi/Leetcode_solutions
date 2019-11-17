// seen[i] means the current maximum possible sum that sum % 3 = i


// Complexity
// Time O(N)
// Space O(1)

// Main idea is to track for each mod 3, maximum sum that could be reach


class Solution {
public:
    int maxSumDivThree(vector<int>& A) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for (int a : A) {
            vector<int> dp2 = {0, 0, 0};
            for (int i = 0; i < 3; ++i)
                dp2[(i + a) % 3] = max(dp[(i + a) % 3], dp[i] + a);
            dp = dp2;
        }
        return dp[0];
    }
};

static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();
