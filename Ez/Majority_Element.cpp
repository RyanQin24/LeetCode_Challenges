//https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        map<int, int> lut;
        for(int i = 0; i < nums.size(); i++){
            if(lut.contains(nums[i])){
                lut[nums[i]] = lut[nums[i]] + 1;
            }else{
                lut[nums[i]] = 1;
            }
            if(lut[nums[i]] > (nums.size()/2)){
                return nums[i];
            }
        }
        return nums[0];
    }
};