//https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        while (i < n){
            if(j >= m + i){
                nums1[j] = nums2[i];
                i++;
                j++;
            }
            else if(nums2[i] < nums1[j]){
                for(int k = m+n-1; k > j; k--){
                    nums1[k] = nums1[k-1];
                }
                nums1[j] = nums2[i];
                i++;
            }else{
                j++;
            }
        }
    }
};