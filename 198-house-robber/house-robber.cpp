class Solution {
public:
    int robb(vector<int> &nums,int i){
        if( i >= nums.size()) return 0;

        int rob1 = nums[i] + robb(nums,i+2);
        int rob2 = robb(nums,i+1);
        return max(rob1,rob2);
    }
    int robbMemo(vector<int> &nums,vector<int>&dp,int i){
        if( i >= nums.size()) return 0;
        int n = nums.size();
        if(dp[i] !=-1) return dp[i];

        int rob1 = nums[i] + robbMemo(nums,dp,i+2);
        int rob2 =robbMemo(nums,dp,i+1);
        return dp[i] =  max(rob1,rob2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n+1,-1);
        int ans = robbMemo(nums,dp,0);
        return ans;
    }
};