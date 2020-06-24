class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int r = arr.size();
        if(!r) return 0;
        int c = arr[0].size();
        vector<vector<int> dp(r+1,vector<int>(c+1,0));
        
        //last row 
        for(int i = 0; i < c; i++){
            dp[i][j] = 
        }
        
        for(int i = r-2; i >= 0; i--){
            for(int j = c-2; j >= 0; j--){
                
                dp[i][j] = min(dp[i+1][j]-arr[i][j], dp[i][j+1]-arr[i][j]);
            }
        }
        
        return dp[0][0];
    }
};