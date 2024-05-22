class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int psum = 0;
        vector<int>ans;
        psum = nums[0];
        ans.push_back(psum);

        for(int i=1;i<nums.size();i++){
            psum+=nums[i];
            ans.push_back(psum);

        }
        return ans;
    }
};