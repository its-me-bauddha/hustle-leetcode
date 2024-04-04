class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxElement =-1;
        unordered_map<int,int >mp;
        for(auto it : nums){
            if(maxElement < it){
                maxElement = it;
            }
            mp[it]++;
        }
        int ans = -1;
        
        for(int i=0;i<mp.size();i++){
            
            if(mp[i] == 0 ) {
                ans = i;
            }
        }
        if(ans == -1)
            return maxElement+1;
        else 
        return ans;
    }
};