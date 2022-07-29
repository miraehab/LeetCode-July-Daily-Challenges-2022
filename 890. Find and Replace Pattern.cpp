class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); ++i){
            unordered_map<char, int> mp;
            unordered_set<char> prev;
            int cnt = 0;
            for(int j = 0; j < words[i].length(); ++j){
                if(mp.find(pattern[j]) != mp.end()){
                    if(mp[pattern[j]] != words[i][j] - 'a'){
                        break;
                    }
                }else{
                    if(prev.find(words[i][j]) != prev.end()) break;
                    mp[pattern[j]] = words[i][j] - 'a';
                    prev.insert(words[i][j]);
                }
                ++cnt;
            }
            
            if(cnt == words[i].length()) ans.push_back(words[i]);
        }
        
        return ans;
    }
};