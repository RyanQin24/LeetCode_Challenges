//https://leetcode.com/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removals = 0;
        int N = nums.size();
        int i = 0;
        while (i < N){
            if(nums[i] == val){
                removals++;
                for(int j = i+1; j < N; j++){
                    nums[j-1] = nums[j];
                }
                N--;
            }else{
                i++;
            }
        }
        return N;
    }
};