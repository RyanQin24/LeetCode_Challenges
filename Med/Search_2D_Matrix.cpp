https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int columnsize = matrix[0].size();
        int start = 0;
        int end = matrix.size()*matrix[0].size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            int rowindex = mid/columnsize;
            int columnindex = mid % columnsize;
            if(matrix[rowindex][columnindex] == target){
                return true;
            }else if(matrix[rowindex][columnindex] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }
};