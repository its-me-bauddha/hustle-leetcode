class Solution {
public:
    int countDigit(int n){
        int count =0;
        while(n >0){
            count++;
            n /= 10;
        }
        return count;
    }
    int reverse(int x) {
        long long reverseDigit = 0;
        
        int N = abs(x) ;
        int count = countDigit(N);

      
       while(N!=0)
       {
        int digit = N%10;
        reverseDigit = reverseDigit*10 + digit;
        N = N/10;
       }
        if(x >= 0 &&reverseDigit <= INT_MAX )
        return reverseDigit;
        else if(reverseDigit > INT_MAX) return 0;
        else 
            return  reverseDigit* -1;
    }
};