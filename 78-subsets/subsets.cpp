class Solution {
public:
    void subsethelper(vector<int>& nums , vector<int>& temp ,int i ,vector<vector<int>> &ans){
         ans.push_back(temp);

        for(int j = i ; j < nums.size();j++){
        temp.push_back(nums[j]);
        subsethelper(nums,temp,j+1,ans);
        temp.pop_back(); 
        }
       }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp ;
        subsethelper(nums,temp,0,ans);
        return ans;
    }
};