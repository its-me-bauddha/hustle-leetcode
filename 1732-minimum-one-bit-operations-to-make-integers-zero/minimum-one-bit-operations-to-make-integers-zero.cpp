class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        if(n == 0) return 0; // no operations

        vector<long long > F(31,0);
        // create F array
        // F[i] ->number of operations to convert a number (having only ith bit set ) to 0
        F[0] = 1;

        for(int i = 1 ; i<=30;i++){
            F[i] = 2*F[i-1] + 1;
        }

        int result = 0 ;
        int sign = 1;

        for(int i = 30 ;i>=0;i--){ // left to right
                int ithBit = ((1 << i ) & n);

                if(ithBit == 0) continue;

                if(sign > 0 ){
                    result += F[i];
                }else{
                    result -= F[i];
                }
                sign  = sign*(-1);
        }

        return result;

    }
};