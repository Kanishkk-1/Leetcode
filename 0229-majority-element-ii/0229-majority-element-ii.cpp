class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int q = n / 3;
        vector<int>no;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        for (auto x: mp) {

            if (x.second > q) {
                no.push_back(x.first);
            }
        }
        return no;
    }
};