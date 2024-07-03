class Solution {
public:
    int atMost(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = nums.size();
        unordered_map<int, int> mp;

        while (r < n) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }

            cnt +=( r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};