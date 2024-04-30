class Solution {
public:
    int countOneBits(int num){
        int countOne = 0 ;
        while(num != 0 ){
        if((num& 1) == 1 ) countOne++;
             num>>=1;
        }
        return countOne;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int & a ,int & b){
            int count1BitInA = countOneBits(a);
            int count1BitInB = countOneBits(b);

            if(count1BitInA == count1BitInB)
                return a < b ;
            else 
                return count1BitInA < count1BitInB;
         };

        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};