class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int>ans;
        vector<int>v(1001,0);
        for(auto x: nums1){
            v[x]=1;
        }
       for(auto x: nums2){
           if(v[x]==1)
           v[x]=2;
       }

       for(int i =0; i<1001;i++){
           if(v[i]==2){
            ans.push_back(i);
           }
       }

       return ans;
    }
};