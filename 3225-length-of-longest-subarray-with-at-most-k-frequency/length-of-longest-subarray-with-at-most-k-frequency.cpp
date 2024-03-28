class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0 ;

       unordered_map<int,int>countMap;
       int n = nums.size();
       int start = 0;
       int end = 0 ;

      while(end < n ){
            // insert the element 
            countMap[nums[end]]++;

            // when frequency of element exceeds the limit k
            if(countMap[nums[end]]  > k ){
                while(nums[start] != nums[end]){
                    countMap[nums[start]]--;
                    start++;
                }
                countMap[nums[start]]--;
                start++;
            }
            // store the ans
            ans = max(ans , end - start + 1);
            end++;
      }
        return ans;
    }
};