class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
         vector<int> ans;
        int i = 0 ;
        int n = ast.size();
        
            
        while(i < n ){
            if(st.empty() || ast[i] > 0 || st.top() < 0){
                st.push(ast[i++]);
            }
            else if(st.top() > abs(ast[i])) i++;
            else if(st.top() == abs(ast[i])) st.pop(),i++;
            else st.pop();
        }

        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};