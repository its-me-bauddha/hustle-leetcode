class Solution {
public:
    int myAtoi(string s) {
        int index = 0 ,  numSign = 1; 
        long ans = 0 ;

        while(index < s.length() && s[index] == ' ') 
            index++;
        if(s[index] == '-')
        { numSign = -1;
           index++;
        }
        else if(s[index] == '+') index++;
        
        while(index < s.length()){
            if(s[index] >= '0' && s[index] <= '9'){
                ans = ans*10 + (s[index] - '0');
                if(ans > INT_MAX && numSign == -1) return INT_MIN;
                else if(ans > INT_MAX && numSign == 1) return INT_MAX;
               index++;
            }
            else 
              return  ans*numSign;
        }
        return ans*numSign;
    }
};