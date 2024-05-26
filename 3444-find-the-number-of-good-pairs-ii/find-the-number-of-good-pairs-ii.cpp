class Solution{

public:
  typedef  long long   ll;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int ,int >mp;

        for(auto element : nums2){
            mp[element*k]++;
        }

        ll ans = 0;

        for(auto element : nums1){
            if(element%k !=0 ) continue;
            for(auto factor = 1 ; factor* factor <= element;factor++){
                if(element % factor != 0)continue;
                int f1 = factor , f2 = element/factor;
                ans += mp[f1];
                if(f1 != f2) ans += mp[f2];
            }
        }

        return ans;
    }
};