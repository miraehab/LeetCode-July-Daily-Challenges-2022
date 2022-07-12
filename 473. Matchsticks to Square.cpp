class Solution {

    int c1, c2, c3, c4;
    bool BackTracking(vector<int>& matchsticks,int i){

        if(i == matchsticks.size()){
            if(c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) return true;
            else return false;
        }
        
        if(matchsticks[i] <= c1){
            c1 -= matchsticks[i];
            if(BackTracking(matchsticks,i+1)) return true;
            c1 += matchsticks[i];    
        }
        
        if(matchsticks[i] <= c2){
            c2 -= matchsticks[i];
            if(BackTracking(matchsticks,i+1)) return true;
            c2 += matchsticks[i];                      
        }
        
        if(matchsticks[i] <= c3){
            c3 -= matchsticks[i];
            if(BackTracking(matchsticks,i+1)) return true;
            c3 += matchsticks[i];     
        }
        
        if(matchsticks[i] <= c4){
            c4 -= matchsticks[i];
            if(BackTracking(matchsticks,i+1)) return true;
            c4 += matchsticks[i];      
        }
		
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {

        if(matchsticks.size()<4) return false;
        
		int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        
		int sizeSum=sum/4;
        c1 = sizeSum, c2 = sizeSum, c3 = sizeSum, c4 = sizeSum;
        
		sort(matchsticks.rbegin(), matchsticks.rend());
        
		return BackTracking(matchsticks,0);
    }
};