class Solution {
public:
    void uniquePaths_helper(vector<vector<int>>&mat,int row,int col ,int &ans){
          
        int m = mat.size()-1 ;
        int n = mat[0].size()-1;
        if(row == m  && col == n) return ;
      
        if(row>=0 && col >=0  && row < m && col < n ){
            ans++;
            uniquePaths_helper(mat,row+1,col,ans);
            uniquePaths_helper(mat,row,col+1,ans);
            
        }
       
    }
    int uniquePaths_helperMemo(int row,int col ,int m ,int n,vector<vector<int>>&dp){
        if(row == m-1 && col == n-1) return 1;

        int down=0,right=0;
        if(dp[row][col]!=-1) return dp[row][col];

        if(row == m-1)
            //edge case-when we are on last row we can only go to right
            right = uniquePaths_helperMemo(row,col+1,m,n,dp); 
        if(col == n-1)
            //edge case-when we are on last row we can only go to right
            down =  uniquePaths_helperMemo(row+1,col,m,n,dp); 
        
        if(row>=0 && col >=0  && row < m && col < n ){
          

           down  =uniquePaths_helperMemo(row+1,col,m,n,dp); 
           right =uniquePaths_helperMemo(row,col+1,m,n,dp); 
            
        }
        return dp[row][col] = down + right;
       
    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
        return uniquePaths_helperMemo(0,0,m,n,dp);
    }
};