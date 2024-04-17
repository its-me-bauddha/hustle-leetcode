class Solution {
public:
    void  subset_helper(vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp,int start){

       ans.push_back(temp);
       for(int i = start ;i < nums.size();i++){
        temp.push_back(nums[i]);
        subset_helper(nums,ans,temp,i+1);
        temp.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans ;
        vector<int>temp;
        subset_helper(nums,ans,temp,0);
        return ans;
    }
};