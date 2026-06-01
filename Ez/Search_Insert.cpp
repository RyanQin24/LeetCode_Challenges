//https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarysearch(nums,target,0,nums.size()-1);
    }
    int binarysearch(vector<int>& nums, int target, int minind, int maxind){
        int mid = (minind + maxind)/2;
        while(minind <= maxind){
            mid = (minind + maxind)/2;
            if(target == nums[mid]){
                return mid;
            }else if (nums[mid] > target){
                maxind = mid - 1;
            }else{
                minind = mid + 1;
            }
        }
        
        if(target > nums[mid]){
            return mid + 1;
        }
            return mid;
    }
};