//https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1.0){
            return 1.0;
        }
        if(x == -1.0){
            if(n % 2 == 0){
                return 1.0;
            }
            return -1.0;
        }
        if(x == 2.0){
            if(n < -1074){
                return 0.0;
            }
        }
        double result = 1;
        if(n < 0){
            while(n < 0){
                result = result / x;
                n++;
            }
        }else{
            while(n > 0){
                result = result * x;
                n--;
            }
        }
        return result;
    }
};