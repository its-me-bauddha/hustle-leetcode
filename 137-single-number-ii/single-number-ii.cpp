class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result =0 ;

        for(int k = 0;k<=31;k++){
            int temp = (1<<k);  // left shift k times
            int countOnes = 0 ;
         
            for(int &num : nums){
                if((num & temp) == 0 ){// the kth bit of num is zero
                   
                }else{
                    countOnes++;
                }

            }

            if(countOnes%3  == 1){
                result = (result | temp); // set kth bit
            }

        }
        return result;
    }
};