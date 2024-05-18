class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans =INT_MIN;

        int left= 0;
        int  right = n-1;
        while(left <right){
            if(height[left] <= height[right]){
                int area = height[left] * (right - left);
                ans = max(ans,area);
                left++;
            }else{
                int area = height[right] * (right - left);
                ans = max(ans,area);
                right--;
            }
        }
       
        return ans;
    }
};