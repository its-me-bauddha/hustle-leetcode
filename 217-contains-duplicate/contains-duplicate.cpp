class Solution {
public:
    bool containsDuplicate (vector<int>& nums) {
        unordered_set<int>hset;
        for(auto num :nums){
            if(hset.count(num) > 0){
                return true;
            }
            hset.insert(num);
        }
        return false;
    }
};