class Solution {
    vector<vector<bool>> visited;
public:
    int getArea(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0)
            return 0;
        
        visited[row][col] = true;
        
        return (1 + getArea(row + 1, col, grid) + getArea(row - 1, col, grid) + getArea(row, col - 1, grid) + getArea(row, col + 1, grid));
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool> (grid[0].size(), false));
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                ans = max(ans, getArea(i, j, grid));
            }
        }
        
        return ans;
    }
};