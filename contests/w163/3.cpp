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

// Add all together, if sum%3==0, return sum.
// if sum%3==1, remove the smallest number which has n%3==1.
// if sum%3==2, remove the smallest number which has n%3==2.

// one pass, and we need to keep the smallest two numbers that have n1%3==1 and n2%3==2.

class Solution {
    public int maxSumDivThree(int[] nums) {
        int res = 0, leftOne = 20000, leftTwo = 20000;
        for(int n:nums){
            res+=n;
            if(n%3==1){
                leftTwo = Math.min(leftTwo,leftOne+n);
                leftOne = Math.min(leftOne,n);
            }
            if(n%3==2) {
                leftOne = Math.min(leftOne,leftTwo+n);
                leftTwo = Math.min(leftTwo,n);
            }
        }
        if(res%3==0) return res;
        if(res%3==1) return res-leftOne;
        return res - leftTwo;
        
    }
}