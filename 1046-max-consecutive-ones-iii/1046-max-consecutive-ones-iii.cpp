class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int maxi = 0;
        int zerocnt = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                zerocnt++;
            }

            while (zerocnt > k) {
                if (nums[l] == 0) {
                    zerocnt--;
                }
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }
        
        return maxi;
    }
};
