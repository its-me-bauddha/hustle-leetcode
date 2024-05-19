class Solution {
public:
    int isVowel(char vs){
       
            if(vs == 'a' || vs == 'e' || vs == 'i' || vs == 'o' || vs == 'u'){
                return true;
            }
            return false;
        
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int i=0 ,j = 0;
        int maxVowelCount= INT_MIN;
         int vowelCount = 0 ;

        while(j < n ){
            if(isVowel(s[j])){
                 vowelCount++;
            }
            if(j - i + 1 == k ){
                maxVowelCount= max(vowelCount,maxVowelCount);
                if(isVowel(s[i]))
                     vowelCount--;
                i++;
            }
            j++;   
            
        }

        return maxVowelCount;
        
    }
};