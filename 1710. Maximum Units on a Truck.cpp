class Solution {
    static bool compare(vector<int> a, vector<int> b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int ans = 0, i = 0;
        while(truckSize > 0 && i < boxTypes.size()){
            ans+= (min(truckSize, boxTypes[i][0])*boxTypes[i][1]);
            truckSize -= min(truckSize, boxTypes[i][0]);
            ++i;
        }
        return ans;
    }
};