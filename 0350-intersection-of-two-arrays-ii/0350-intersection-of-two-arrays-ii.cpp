class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int , int> mp;
        vector<int>ans;

        for (int i = 0; i < n; i++) {
            mp[nums1[i]]++;
        }

        for(int i=0;i<m;i++){
           if( --mp[nums2[i]]>=0){
                  ans.push_back(nums2[i]);
           }
           
            }
        

        // for(auto i : mp){
        //     if(i.second==0) ans.push_back(i.first);
        // }
        return ans;
    }
};