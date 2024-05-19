class Solution {
public:
    int maxPower(string s) {
        int maxlen = 1 ;

        int count = 1 ;
        int i = 0 ;
        int j = 1;
       
        while(j < s.size()){
            if(s[j] == s[i]) {
                count++;
            }else{
                count = 1;
            }
            maxlen = max(maxlen,count);
            j++,i++;
        }
        return maxlen;
    }
};