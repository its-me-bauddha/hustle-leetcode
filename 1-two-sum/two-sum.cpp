class Solution {
public:
   static bool cmp (pair<int,int> a ,pair <int,int>b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> >arr;
        vector<int>ans;

        for(int i=0; i <nums.size() ;i++){
            arr.push_back({nums[i] ,i});
        }
        sort(arr.begin(),arr.end(),cmp);

        int start = 0 ;
        int end = arr.size()-1;

        while(start < end){
            if((arr[start].first + arr[end].first) == target){
                 ans = {arr[start].second , arr[end].second} ;
                 break;
            } 
            else if((arr[start].first + arr[end].first) > target)
                end--;
            else 
                start++;
        }
        return ans;
    }

};