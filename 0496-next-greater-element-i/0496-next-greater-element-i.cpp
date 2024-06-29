class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge(nums1.size(), -1);
        stack<int> st;
        map<int , int > mp;

        for(int num : nums2){
           
           while(!st.empty() && st.top() < num){
            mp[st.top()]= num;
            st.pop();
           }
           st.push(num);
        }

        for(int i =0 ; i<nums1.size() ;i++){
            if(mp[nums1[i]]) nge[i] = mp[nums1[i]];
        }
        return nge;
    }
};