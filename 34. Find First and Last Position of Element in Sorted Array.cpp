class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //vector<int> ans = {-1, -1};
        
        int start = 0, end = nums.size()-1, mid, first = -1, last = -1;
        
        while(start <= end){
            mid = (end+start)/2;
            if(nums[mid] == target){
                first = mid;
                last = mid;
                break;      
            }else if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        
        int l1 = 0, l2 = mid + 1, r1 = mid - 1, r2 = nums.size()-1;
        while(first != -1 && l1 <= r1){
            mid = (l1+r1)/2;
            if(nums[mid] == target){
                first = mid;  
                r1 = mid - 1;
            }else if(nums[mid] > target) r1 = mid - 1;
            else l1 = mid + 1;
        }
        
        while(last != -1 && l2 <= r2){
            mid = (l2+r2)/2;
            if(nums[mid] == target){
                last = mid;  
                l2 = mid + 1;
            }else if(nums[mid] > target) r2 = mid - 1;
            else l2 = mid + 1;
        }
        
        return {first, last};
    }
};