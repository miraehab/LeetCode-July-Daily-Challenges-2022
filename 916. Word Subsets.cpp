class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>> w1_freq(words1.size(), vector<int> (26, 0));
        vector<string> ans;
        
        for(int i = 0; i < words1.size(); ++i){
            for(int j = 0; j < words1[i].size(); ++j){
                w1_freq[i][words1[i][j] - 'a']++;
            }
        }
        
        vector<int> w2_freq(26, 0);
        for(int i = 0; i < words2.size(); ++i){
            for(int j = 0; j < words2[i].size(); ++j){
                w2_freq[words2[i][j] - 'a'] = max(int(w2_freq[words2[i][j] - 'a']), int(count(words2[i].begin(), words2[i].end(), words2[i][j])));
            }
        }
        
            
        for(int j = 0; j < words1.size(); ++j){
            int cnt = 0;
            for(int k = 0; k < 26; ++k){
                if(w2_freq[k] > 0 && w2_freq[k] > w1_freq[j][k]) break;
                ++cnt;
            }
            if(cnt == 26) ans.push_back(words1[j]);
        }
        
        return ans;
    }
};