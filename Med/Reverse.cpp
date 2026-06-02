//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        vector<int> digits;
        vector<int> limit = {2,1,4,7,4,8,3,6,4,7};
        bool sign = (x > 0);
        while(x != 0){
            int temp = x % 10;
            if(temp < 0){
                temp = temp *-1;
            }
            digits.push_back(temp);
            x = x/10;
        }
        int result = 0;
        bool in_limit = digits.size() < limit.size();
        for(int i = 0; i < digits.size(); i++){
            if(!in_limit){
                if((i != digits.size()-1 && limit[i] < digits[i])){
                    return 0;
                }else if((limit[i] < digits[i])||(!sign && (limit[i] + 1) < digits[i])){
                    return 0;
                }else if ((i != digits.size()-1 && limit[i] > digits[i])){
                    in_limit = true;
                }
            }
            result = result * 10;
            if(sign){
                result = result + digits[i];
            }else{
                result = result - digits[i];
            }
        }
        return result;
    }
};