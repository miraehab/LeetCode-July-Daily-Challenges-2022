class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        multiset<int> s_nums;
        for(int i = 0; i < nums.size(); ++i)s_nums.insert(nums[i]);
        int ans = 1, prev = *(s_nums.begin()), maxi = 1;
        for(auto i = s_nums.begin(); i != s_nums.end(); ++i){
            if(i == s_nums.begin() || prev == *i) continue;
            if(*(i) - prev == 1) ++ans;
            else ans = 1;
            maxi = max(ans, maxi);
            prev = *i;
        }
        return maxi;
    }
};