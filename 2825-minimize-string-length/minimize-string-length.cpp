class Solution {
public:
    int minimizedStringLength(string s) {
        sort(s.begin(),s.end());
        stack<char>st;

        for(auto it:s){
            if(st.empty())
                st.push(it);
            else{
                if(st.top() == it) 
                    continue ; 
                else 
                    st.push(it);
            }
        }

        return st.size();
    }
};