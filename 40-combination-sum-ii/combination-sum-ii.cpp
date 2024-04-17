class Solution {
public:
    void combinationSum2_helper(vector<int>& cand, vector<vector<int>> &ans,vector<int>& temp,int target,int index){
       
        if(target == 0 ){
            ans.push_back(temp);
            return ;
        }

        for(int i=index;i<cand.size();i++){
            if(cand[i] > target) break;
            if(i > index && cand[i] == cand[i-1])
            continue;

            temp.push_back(cand[i]);
            combinationSum2_helper(cand,ans,temp,target-cand[i] , i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<vector<int>> ans;
        vector<int>temp ;
        combinationSum2_helper(cand,ans,temp,target,0);
        return ans;
    }
};