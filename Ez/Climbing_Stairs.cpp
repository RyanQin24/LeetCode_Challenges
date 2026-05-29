//https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        int sum = 1;
        for(int i = 1; i <= n/2; i++){
            int total_steps = i + (n-2*i);
            sum += choose(total_steps,i);
        }
        return sum;
    }
    int choose(int n, int k){
        int temp = k;
        return (int)(permutation_factorial(n,n,k,temp) / factorial(temp));
    }
    long long factorial(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        return ((long long) n)*factorial(n-1);
    }
    long long permutation_factorial(int n, int i, int k, int &redfact){
        long long red_i = reduce(i, redfact);
        if(i == n-k+1){
            return ((long long) red_i);
        }
        return ((long long) red_i) * permutation_factorial(n,i-1,k,redfact);
    }
    long long reduce(int i, int &redfact){
        long long ret_val = (long long) i;
        while(redfact != 0 && ret_val % redfact == 0){
            ret_val = ret_val / (long long) redfact;
            redfact--;
        }
        return ret_val;
    }
};