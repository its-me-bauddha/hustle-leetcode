class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int maxElement = -1;
        int end = n - 1;
        while(end != 0 ){

            ans[end] = maxElement;
            if(arr[end] > maxElement)
                maxElement = arr[end];
            end--;
               
        }
        ans[0] = maxElement;
        return ans;
    }
};