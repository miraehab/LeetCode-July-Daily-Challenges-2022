class Solution {
public:
    const int MAX_COST = 1000001;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<int>> prevMemo(target + 1, vector<int>(n, MAX_COST));
       
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                prevMemo[1][color - 1] = 0;
            } else if (!houses[0]) {
                prevMemo[1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            vector<vector<int>> memo(target + 1, vector<int>(n, MAX_COST));
            
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    if (houses[house] && color != houses[house]) {
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            currCost = min(currCost, prevMemo[neighborhoods - 1][prevColor - 1]);
                        } else {
                            currCost = min(currCost, prevMemo[neighborhoods][color - 1]);
                        }
                    }

                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
            prevMemo = memo;
        }
        
        int minCost = MAX_COST;

        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, prevMemo[target][color - 1]);
        }
    
        return minCost == MAX_COST ? -1 : minCost;
    }
};