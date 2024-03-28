class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       
        int sum = 0;
        int start = 0 ;
        int end = 0;
        int len = INT_MAX;
        while( end < nums.size() ){
            // include the current num 
            sum += nums[end];
            while(sum >= target){
                // minimise -> remove from the sum
                // update the len
                len = min (len , end - start + 1);
                sum -= nums[start];
                start++;

            }
           end++;
        }
        if(len == INT_MAX) return 0;
        else return len;
    }
};