class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(),nums.end());

        int countZero = 0, countOne = 0 , countTwo = 0 ;
        if(nums.size() == 1) return;
        for(auto i : nums){
            if(i == 0 ) 
                countZero++;
            else if(i == 1) 
                countOne++;
            else 
                countTwo++;
        }

        int i = 0;
        while(countZero > 0 && i < nums.size()){
            nums[i] = 0;
            countZero--;
            i++;
        }
        while(countOne > 0 && i < nums.size() ){
            nums[i]= 1;
            countOne--;
            i++;

        }
        while(countTwo > 0 && i < nums.size() ){
            nums[i] = 2;
            countTwo--;
            i++;

        }

    }
};