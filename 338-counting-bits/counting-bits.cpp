class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>  ans;

        for(int i = 0; i<=n;i++){
            int result = 0;
            int x = i; 
            while( x != 0 ){
                if((x&1) == 1) result++;
                x >>= 1;
            }
            ans.push_back(result);
        }

        return ans;
    }
};