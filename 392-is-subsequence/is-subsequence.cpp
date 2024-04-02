class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0 ;

        while(i<s.size()&& j<t.size()){
            // both chars are equal than move the pointers to the next char 
            if(s[i] == t[j])
                i++;
            j++;
            
        }
        if(i == s.size())
        return true;
        else return false;
    }
};