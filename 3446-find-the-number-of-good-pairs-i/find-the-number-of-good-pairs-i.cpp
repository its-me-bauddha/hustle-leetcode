class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0 ;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]%(nums2[j]*k) == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};