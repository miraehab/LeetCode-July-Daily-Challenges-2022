class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;
        
        for(int i = 0; i < s.length(); ++i) s_freq[s[i]]++;
        for(int i = 0; i < t.length(); ++i) t_freq[t[i]]++;
        
        for(char i = 'a'; i <= 'z'; i++){
            if(s_freq[i] != t_freq[i]) return false;
        }
        
        return true;
    }
};