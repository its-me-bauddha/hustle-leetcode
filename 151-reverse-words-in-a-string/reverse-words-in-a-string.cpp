class Solution {
public:
    string reverseWords(string s) {
       
        string ans="";
        
        stringstream ss(s);
        string token ="";

        while(ss >> token){
         
            ans = token + " " + ans;
        }
        int n = ans.size();
        return ans.substr(0,n-1);
    }
};