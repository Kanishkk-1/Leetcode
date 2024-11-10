class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>set;
        int n = nums.size();
        for(int i =0 ; i<n ;i++){
            set.insert(nums[i]);
        }

        int y = set.size();

        if(y<n) return true;
        else return false;
    }
};