class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int i=0 , j = 0 ;
       int n = nums.size();
       int maxlen = INT_MIN;
       int zeroCount=0;

       while(j < n ){
        if(nums[j] == 0)
            zeroCount++;
            
        while(zeroCount > k ){
                if(nums[i] == 0)
                    zeroCount--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
    
        
       }
       return maxlen;
    }
};