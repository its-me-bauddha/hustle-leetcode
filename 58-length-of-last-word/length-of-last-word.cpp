class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordlen = 0 ;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == ' ' &&lastWordlen == 0 ) continue;
            if(s[i] != ' ' ) lastWordlen++;
            if(s[i] == ' ' && lastWordlen != 0) break;
           
        }

        return lastWordlen;
    }
};