class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int newTarget = target - nums[i];
            if(mp.count(newTarget)){
                return {mp[newTarget],i};
            }
            mp[nums[i]] = i ;
        }
        return {};
    }

};