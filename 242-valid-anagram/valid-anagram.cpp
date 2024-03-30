class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(int i=0;i<s.size();i++){
            
            char ch = s[i];
            int index = ch -'a';
            arr1[index]++;
            
        }
        for(int i=0;i<t.size();i++){
            
            char ch = t[i];
            int index = ch-'a';
            arr2[index]++;
            
        }
        for(int i=0;i<26;i++){
            cout << arr1[i];
            if(arr1[i] != arr2[i])return false;
        }
        return true;

       
    }
};