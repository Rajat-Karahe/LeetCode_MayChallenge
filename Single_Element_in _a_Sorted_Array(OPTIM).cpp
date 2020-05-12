// O(logN)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int si =0;
        int ei =nums.size()-1;
        
        if(ei == 0){
            return nums[0];
        }
        
        if(nums[0] != nums[1]){
            return nums[0];
        }
        
        if(nums[ei] != nums[ei-1]){
            return nums[ei];
        }
        
        while(si <= ei){
            if(si == ei){
                return nums[si];
            }
            
            int mid = (si + ei)/2;
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            else if(nums[mid-1] == nums[mid]){
                if((mid - si)%2 == 1){
                    si = mid+1;
                }
                else{
                    ei = mid-2;
                }
            }
            else{
                if((ei - mid)%2 == 1){
                    ei = mid-1;
                }
                else{
                    si = mid+2;
                }
            }
        }
        
        return -1;
    }
};
