class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =  0 ;
        int n = nums.size();

        int maxlen = INT_MIN;
        int i = 0 ;
        
        while(i < n ){
            if(nums[i] != 1)
                count = 0 ;
            else count++;
            maxlen = max(maxlen,count);
            i++;
        }
        return maxlen;
    }
};