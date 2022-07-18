class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() , cols = matrix[0].size();
        
        if(rows < 1)
            return 0;
        
        for(int i = 0; i < rows; ++i){
            for(int j = 1; j < cols; ++j){
                matrix[i][j] =  matrix[i][j] + matrix[i][j -1];
            }
        }
      
        int count = 0, sum = 0;
        unordered_map<int , int> counter;
        for(int colstart = 0; colstart < cols; ++colstart){
            for(int col = colstart; col < cols; ++col){
                counter.clear();
                counter[0] = 1;
                sum = 0;
                for(int row = 0; row < rows; ++row){
                    
                    sum += matrix[row][col] - (colstart > 0 ? matrix[row][colstart - 1] : 0 );
                    count += (counter.find(sum- target) != counter.end() ? counter[sum-target] : 0);
                    counter[sum]++;
                }
            }
        }
        return count;
    }
};