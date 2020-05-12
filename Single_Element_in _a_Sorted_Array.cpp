//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
//Your solution should run in O(log n) time and O(1) space.

//complexity :- O(N); better than 14% of submissions

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int length = nums.size();
        int i=0;
        while(i<length-1){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
            i += 2;
        }
        
        return nums[i];
    }
};
