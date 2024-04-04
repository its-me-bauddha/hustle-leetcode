class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int >mp;
        for(auto it : nums){
            mp[it]++;
        }
        int ans = -1;
        for(int i=0;i<mp.size();i++){
            
            if(mp[i] == 0 ) {
                ans = i;
            }
        }
        if(ans == -1)
            return nums[nums.size()-1 ]+1;
        else 
        return ans;
    }
};