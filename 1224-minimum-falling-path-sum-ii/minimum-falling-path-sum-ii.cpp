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
    
    int solveTab(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp (n ,vector<int>(n,INT_MAX));


        for(int col = 0 ; col<n ;col++){
            dp[n-1][col] = grid[n-1][col];
        }

        for(int row= n-2 ;row>= 0; row--){
            for(int col = 0 ;col<n ;col++){
                int ans = INT_MAX;

                for(int nextCol = 0 ;nextCol < n ;nextCol++){
                    if(nextCol != col){
                        ans = min(ans,dp[row+1][nextCol]);
                    }
                }
                dp[row][col] = ans + grid[row][col];
            }
            
        }

        int result = INT_MAX ; 
        for(int col = 0 ; col < n ;col++){
            result = min (result ,dp[0][col]);
        }
        return result;
    }

int solveSpaceOP1(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp (n ,vector<int>(n,INT_MAX));
        int nextMinCol1 = -1; //col of first min value in row+1
        int nextMinCol2 = -1; //col of second min value in row+1

        for(int col = 0 ; col<n ;col++){
            dp[n-1][col] = grid[n-1][col];

            if(nextMinCol1 == -1 || dp[n-1][col] <= dp[n-1][nextMinCol1]){
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = col;
            }else if(nextMinCol2 == -1 || dp[n-1][col] <= dp[n-1][nextMinCol2]){
                nextMinCol2 = col;
            }
        }

        for(int row= n-2 ;row>= 0; row--){
            int minCol1 = -1; // stores the first  min value at curr row
            int minCol2 = -1;
            for(int col = 0 ;col<n ;col++){
               
               if(col != nextMinCol1){
                    dp[row][col] = grid[row][col] + dp[row+1][nextMinCol1];
               }else{
                     dp[row][col] = grid[row][col] + dp[row+1][nextMinCol2];
               }

               if(minCol1 == -1 || dp[row][col] <= dp[row][minCol1]){
                    minCol2 = minCol1;
                    minCol1 = col;
               }else if(minCol2 == -1 || dp[row][col] <= dp[row][minCol2]){
                    minCol2 = col;
               }

            }

            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;    
        }

        
        return dp[0][nextMinCol1];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

    

        // int result = solveTab(grid); 
        int result = solveSpaceOP1(grid); 
        //  vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        // for(int col = 0 ; col < n ;col++){
        //    // result = min(result , solveRec(grid,col,0));
        //      result = min(result , solveMemo(grid,col,0,dp));
        // }
        return result;
    }
};