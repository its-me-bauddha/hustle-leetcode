class Solution {
public:
    int recSolve(vector<vector<int>>& matrix,int row,int col){
        int n  = matrix.size();
        int m = matrix[0].size();

        if(row == n-1){
            return matrix[row][col];
        }
        int minSum = INT_MAX;
        int sum  =0;
        sum= matrix[row][col];

        if(row +1< n && col-1 >= 0 ){
            minSum = min(minSum , sum + recSolve(matrix,row+1,col-1));
        }
        minSum = min(minSum , sum + recSolve(matrix,row+1,col));
        if(row+1 < n && col+1 < m ){
            minSum = min(minSum , sum + recSolve(matrix,row+1,col+1));
        }
        return minSum;
    }
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& memo, int n, int m, int row, int col) {
        if (row == n - 1) return matrix[row][col];
        
        // If result is already computed, return memoized value
        if (memo[row][col] != INT_MAX)
            return memo[row][col];
        
        int left = (col > 0) ? helper(matrix, memo, n, m, row + 1, col - 1) : INT_MAX;
        int down = helper(matrix, memo, n, m, row + 1, col);
        int right = (col < m - 1) ? helper(matrix, memo, n, m, row + 1, col + 1) : INT_MAX;

        // Store computed result in memoization vector
        memo[row][col] = matrix[row][col] + min(left, min(down, right));
        
        return memo[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();

        int row = 0 ;
        int minSum = INT_MAX;
        vector<vector<int>>dp(101,vector<int>(101,INT_MAX));
        for(int col = 0 ; col < m ;col++){
            // minSum = min(minSum , recSolve(matrix ,row,col));
            minSum = min(minSum , helper(matrix ,dp,n,m,0,col));

        }
        return minSum;
    }
};