class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0 ;
        int ans = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int num : nums){
            // for -ve remainder , it will make as it positive
            sum = (((sum + num)% k) + k)%k;

            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            mp[sum]++;
        }

        return ans;
    }
};