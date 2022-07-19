class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i = 1; i <= numRows; ++i){
            vector<int> tmp(i);
            tmp[0] = 1;
            tmp[i-1] = 1;
            
            triangle.push_back(tmp);
        }
        
        for(int i = 2; i < numRows; ++i){
            for(int j = 1; j < triangle[i].size()-1; ++j){
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        
        return triangle;
    }
};