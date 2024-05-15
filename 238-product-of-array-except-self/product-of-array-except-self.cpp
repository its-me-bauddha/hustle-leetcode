class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int product = 1;
        int cntZero = 0;

        bool flag = false;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0){
                product *=nums[i] ;
            }
            else{
                flag = true;
                cntZero++;
            }
           
        }
       
        for(int i = 0 ;i<nums.size();i++){
            if(flag && nums[i] == 0 && cntZero > 1 || flag &&  nums[i]!=0 ){
                ans[i] = 0;
            }else if(flag && nums[i] == 0 && cntZero == 1){
                     ans[i] = product;
            }
            else{
                ans[i] = product/nums[i];
            }
           
        }

        return ans;
    }
};