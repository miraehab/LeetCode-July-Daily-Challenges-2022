class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size(); 
        if(size1 + size2 != size3) return false;
        
        vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1, false));
        dp[0][0] = true;
        
        for(int i2 = 1; i2 <= size2; i2++) dp[0][i2] = dp[0][i2 - 1] && s2[i2 - 1] == s3[i2 - 1];
        for(int i1 = 1; i1 <= size1; i1++) dp[i1][0] = dp[i1 - 1][0] && s1[i1 - 1] == s3[i1 - 1];

        for(int i1 = 1; i1 <= size1; i1++){
            for(int i2 = 1; i2 <= size2; i2++){
                dp[i1][i2] = (dp[i1 - 1][i2] && s1[i1 - 1] == s3[i1 + i2 - 1]) || (dp[i1][i2 - 1] && s2[i2 - 1] == s3[i1 + i2 - 1]);
            }
        }
        
        return dp[size1][size2];  
    }
};

