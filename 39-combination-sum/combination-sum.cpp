class Solution {
public:
    void  combinationSum_helper(vector<int>& can , int target,  vector<vector<int>> &ans,vector<int>& curr,int index){
      
         if(index >= can.size() ||  target < 0 ){
            
            return;
         }
         if(target == 0 ) {
            ans.push_back(curr);
            return;
         }

        curr.push_back(can[index]);

        combinationSum_helper(can , target-can[index], ans,curr,index);
        curr.pop_back();
        combinationSum_helper(can , target, ans,curr,index+1);
            
    }

    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans ; 
        vector<int> curr;
        combinationSum_helper(can , target, ans,curr,0);
        return ans;
    }
};