class Solution {
public:
    int dfs(vector<int>&nums,int index,int currXor){
        if(index == nums.size()){
            return currXor;;
        }

        int include = dfs(nums,index+1,currXor^nums[index]);
        int exclude = dfs(nums,index+1,currXor);

        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};