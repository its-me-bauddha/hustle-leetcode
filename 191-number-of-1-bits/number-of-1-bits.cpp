class Solution {
public:
    int hammingWeight(int n) {
    int  oneBit = 0;
       while(n != 0){
         if((n&1) == 1){
            oneBit++;
         }
         n >>= 1;
       }
       return oneBit;
    }
};