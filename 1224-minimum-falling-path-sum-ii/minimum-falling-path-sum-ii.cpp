class Solution {
public:
    int solveRec (vector<vector<int>>& grid , int col ,int row){
        int n = grid.size();
        if(row == n-1){
            return grid[row][col];
        }

        int ans = INT_MAX;
        for(int nextCol = 0 ; nextCol < n ; nextCol++){
            if(nextCol != col ){
                ans = min(ans,solveRec(grid,nextCol , row+1));
            }
        }

        return grid[row][col] + ans;
    }

    int solveMemo (vector<vector<int>>& grid , int col ,int row,vector<vector<int>>& dp){
        int n = grid.size();
        if(row == n-1){
            return grid[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];
        int ans = INT_MAX;
        for(int nextCol = 0 ; nextCol < n ; nextCol++){
            if(nextCol != col ){
                ans = min(ans,solveMemo(grid,nextCol , row+1,dp));
            }
        }

        dp[row][col] = grid[row][col] + ans;
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int result = INT_MAX ;
         vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        for(int col = 0 ; col < n ;col++){
           // result = min(result , solveRec(grid,col,0));
             result = min(result , solveMemo(grid,col,0,dp));
        }
        return result;
    }
};