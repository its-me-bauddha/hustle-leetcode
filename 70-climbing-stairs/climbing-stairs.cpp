class Solution {
public:
    int solveRec(int n){
        if(n==1) return 1;
        if(n ==2) return 2;

        return solveRec(n-1) + solveRec(n-2);
    }
    int solveMemo(int n,vector<int>&dp){
        if(n==1) return 1;
        if(n ==2) return 2;

        if(dp[n] != -1) return dp[n];
        return dp[n] =  solveMemo(n-1,dp) + solveMemo(n-2,dp);
    }
    int climbStairs(int n) {
        // return solveRec(n);
        vector<int>dp(n+1,-1);
              return solveMemo(n,dp);
    }
};