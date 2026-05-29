//https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vect;
        if(numRows >= 1){
            vect.push_back({1});
        }
        if(numRows >= 2){
            vect.push_back({1,1});
        }
        for(int i = 3; i <= numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j < i-1; j++){
                temp.push_back((vect[i-2][j-1] + vect[i-2][j]));
            }
            temp.push_back(1);
            vect.push_back(temp);
        }
        return vect;
    }
};