class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        int i = 0;   
        long m = 1; 

        while (m <= n)
        if (i < nums.size() && nums[i] <= m) {
            m += nums[i++];
        } else {
            m += m;
            ++ans;
        }

        return ans;
    }
};