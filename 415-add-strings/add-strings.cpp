class Solution {
public:
    void addStringsRE(string &num1,int p1, string &num2,int p2,string& ans,int carry =0 ) {
            // base case
            if(p1 < 0 && p2 < 0 ){
                if(carry != 0 ){
                     ans.push_back(carry + '0');
                }
                return;
            }

            // ek case solve kro

            int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
            int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

            int csum = n1+n2 + carry;
            int digit  = csum%10;
            carry = csum/10;
            
            ans.push_back(digit + '0');

            addStringsRE(num1,p1-1,num2,p2-1,ans,carry);
            
    }
    string addStrings(string num1, string num2) {
        string ans = "";
        addStringsRE(num1,num1.size()-1,num2,num2.size()-1,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};