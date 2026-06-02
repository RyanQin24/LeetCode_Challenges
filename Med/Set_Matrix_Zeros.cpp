https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> columns;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        for(int i = 0; i < rows.size(); i++){
            int row = rows[i];
            int column = columns[i];
            for(int j = columns[i]-1; j >= 0; j--){
                matrix[row][j] = 0; 
            }
            for(int j = columns[i]+1; j < matrix[0].size(); j++){
                matrix[row][j] = 0; 
            }
            for(int j = rows[i]-1; j >= 0; j--){
                matrix[j][column] = 0; 
            }
            for(int j = rows[i]+1; j < matrix.size(); j++){
                matrix[j][column] = 0; 
            }
        }
    }
};