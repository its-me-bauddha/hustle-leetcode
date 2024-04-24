class Solution {
public:
    int trifib(int n){
        if(n == 0 ) return 0;
        if(n == 1) return 1;
        if(n == 2 ) return 1;

        return trifib(n-3) + trifib(n-2) + trifib(n-1);
    }
    int trifibTopDown(int n , vector<int>&dp){
         if(n == 0 ) return 0;
        else if(n == 1 || n == 2) return 1;
       

        if(dp[n] != 0) return dp[n];
         int ans = trifibTopDown(n-3,dp) + trifibTopDown(n-2,dp) + trifibTopDown(n-1,dp);
         dp[n] = ans;
         return ans;
    }
    int tribonacci(int n) {
       vector <int> dp(n+4, 0);
        return trifibTopDown(n,dp);
    }
};