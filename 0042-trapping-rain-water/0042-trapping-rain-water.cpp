class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while (l <= r) {
            if (nums[l] <= nums[r]) {
                if (leftMax < nums[l])
                    leftMax = nums[l];
                else {
                    water += leftMax - nums[l];
                    l++;
                }
            }else{
                if (rightMax < nums[r])
                    rightMax = nums[r];
                else {
                    water += rightMax - nums[r];
                    r--;
                }
            }

        }
        return water;
    }
};