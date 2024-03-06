class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  l = 0, r = nums.size() - 1;
        int mid = (l + r) / 2;
        while (l < r){
            mid = (l + r) / 2;
            if (nums[mid] < nums[r]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        if (target >= nums[mid]){
            l = mid;
            r = nums.size() - 1;
        }
        else{
            l = 0;
            r = mid - 1;
        }    
        while(l < r){
            mid = (l + r) / 2;
            if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};