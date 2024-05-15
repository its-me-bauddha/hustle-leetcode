class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pro = 1;
        int cnt0 = 0 ;
        bool flag = false;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0){
                pro *=nums[i] ;
               
            }else{
                flag = true;
                cnt0++;
            }
           
        }
       
        for(int i = 0 ;i<nums.size();i++){
            if(flag){
                if(nums[i] == 0    ){
                    if(cnt0 > 1){
                         ans[i] = 0;
                    }else
                     ans[i] = pro;
                }else{
                  ans[i] = 0 ;
                }
            }
            else{
                ans[i] = pro/nums[i];
            }
           
        }

        return ans;
    }
};