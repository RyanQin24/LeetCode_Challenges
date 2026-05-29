//https://leetcode.com/problems/number-of-1-bits/description/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n) {
            count += (n & 1); // check last bit
            n >>= 1;          // right shift
        }

        return count;
    }
};