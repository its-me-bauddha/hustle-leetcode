class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums),end(nums));

        int start = 0;
        int end = nums.size()-1;

        while(start < end && nums[start] != -nums[end]){
            if(-nums[start] > nums[end]) start++;
            else end--;
        }
        return (start < end ) ? nums[end] : -1; 
    }
};