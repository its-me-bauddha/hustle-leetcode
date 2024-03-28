class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int >dq;
        vector<int>ans;

        // process first k elements
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            //insert the element
            dq.push_back(i);
        }

        // store the ans of first window
        ans.push_back(nums[dq.front()]);

        // process remainning windows
        for(int i=k;i<nums.size();i++){
            // remove the element 
            if(!dq.empty() && i - k >= dq.front())
                dq.pop_front();
            
            // add the new element
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
                
            dq.push_back(i);
            // ans store
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
