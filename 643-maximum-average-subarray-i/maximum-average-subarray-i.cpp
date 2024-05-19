class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0 , j = 0 ;
        double avgsum = INT_MIN;
        int n = nums.size();
        double currsum = 0;
        while(j < n){
            if(j - i + 1 < k ){
                currsum += nums[j];
                j++;
            }else{
                currsum += nums[j];
                double x = (double)currsum / k ;
                avgsum = max(avgsum,x);
                 currsum -= nums[i];
                 i++;j++;

            }
        }

        return avgsum;
    }
};