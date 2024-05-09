class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness),end(happiness),greater<int>());
        long long maxHappiness = 0;

        for(int i = 0 ; i  < happiness.size();i++){
            long long currentHappiness = happiness[i] - i ;
            if(currentHappiness >= 0 && k > 0   ){
                maxHappiness += currentHappiness;
                k--;
    
            }
            else{
                break;
            }
          
        }

        return maxHappiness;

    }
};