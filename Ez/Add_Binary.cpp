//https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        string output = "";
        bool carry = false;
        int aind = a.length() - 1;
        int bind = b.length() - 1;
        while (aind >= 0 && bind >= 0){
            output = rippleadd(a[aind], b[bind], carry) + output;
            aind--;
            bind--;
        }
        while (aind >= 0){
            output = rippleadd(a[aind], '0', carry) + output;
            aind--;
        }
        while (bind >= 0){
            output = rippleadd('0', b[bind], carry) + output;
            bind--;
        }
        if(carry){
            output = "1" + output;
        }
        return output;
    }
    string rippleadd(char a, char b, bool &carry){
        if(a == '1' && b == '1' && !carry){
            carry = true;
            return "0";
        }
        if(a == '1' && b == '1' && carry){
            carry = true;
            return "1";
        }
        if(carry && (a == '1' || b == '1')){
            carry = true;
            return "0";
        }
        if(a == '0' && b == '0' && !carry){
            carry = false;
            return "0";
        }
        carry = false;
        return "1";
    }

};