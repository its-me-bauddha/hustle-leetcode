class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0 ;
        for(int i =0;i<s.size()-1;i++){
            char ch = s[i];
            char c = s[i+1];
              int x = ch-'a';
              int  y = c-'a';
                
              sum += abs(y-x);
        }
        return sum;
    }
};