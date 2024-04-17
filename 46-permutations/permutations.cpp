class Solution {
public:
    void permute_helper(vector<int>& nums ,  vector<vector<int>> &ans,int s){
        while( s == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=s;i<nums.size();i++){
            swap(nums[i],nums[s]);
            permute_helper(nums,ans,s+1);
            swap(nums[i],nums[s]);
        }
         
      
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int>temp;
        permute_helper(nums,ans,0);
        return ans;
    }
};