#define LL long long
#define MP MAKE_PAIR
#define F first
#define S second
class Solution {
public:
    vector<LL> findDiagonalOrder(vector<vector<LL>>& nums) {
        LL n = nums.size();
        
        vector<LL> ans;
        for(LL i = 0; i < n; i++){
            //travel diagonal of ith row
            
            LL cols = nums[i].size();
            
            LL j = 0;
            LL row = i;
            while(row >= 0 && j < n)
            {
                if(j > cols) continue;
                ans.push_back(nums[row++][j--]);
            }
        }
        
        return ans;
    }
};