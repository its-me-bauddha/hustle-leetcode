class Solution {
public:
    void subset_solve(int idx ,int &ans,vector<int > &nums,int &k,unordered_map<int,int> &mp){
        
        if(idx >= nums.size()){
            ans++;
            return;
        }
            // not take
            subset_solve(idx+1,ans,nums,k,mp);
            //take 
            if(!mp[nums[idx] - k ] && !mp[nums[idx] + k ]){
                    mp[nums[idx]]++;
                    subset_solve(idx+1,ans,nums,k,mp);
                    
                    mp[nums[idx]]--;
            }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = -1 ;
        unordered_map<int,int> mp;
        subset_solve(0,ans,nums,k,mp);
        
        return ans;
        
    }
};