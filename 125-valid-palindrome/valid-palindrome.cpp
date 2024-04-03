class Solution {
public:
    bool isPalindrome(string s) {
        
        string ans="";
        for(int i =0;i<s.size();i++){
            char ch  = tolower(s[i]);
          
            if(ch >= 'a' && ch <= 'z') 
            ans += ch;
            else if( ch >= '0' && ch <= '9')
                {
                   
                   ans += ch;
                }
        }
         
        int start =0;
        int end = ans.size()-1;
        while(start < end){
            if(ans[start] != ans[end]) return false;
            start++,end--;
        }
        
        return true;
    }
};