https://leetcode.com/problems/pascals-triangle-ii/description/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>v;
        v.push_back(1);
        if(rowIndex == 0){
            return v;
        }
        for(int i = 1; i < rowIndex; i++){
            v.push_back(choose(i,rowIndex));
        }
        v.push_back(1);
        return v;
    }
    int choose(int k, int n){
        long long result = 1;
        long long k_fact = 1;
        for(int i = n-k+1; i <= n; i++){
            result = result * i;
            while(k_fact <= k && result % k_fact == 0){
                result = result / k_fact;
                k_fact++;
            }
        }
        while(k_fact <= k){
                result = result / k_fact;
                k_fact++;
        }
        return result;
    }
};