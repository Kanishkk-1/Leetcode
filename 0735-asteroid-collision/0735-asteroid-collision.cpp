class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (!st.empty()) {
                if (st.top() > 0 && nums[i] > 0) {
                    st.push(nums[i]);
                } else if (st.top() > 0 && nums[i] < 0) {
                    while (!st.empty() && st.top() > 0 && st.top() < abs(nums[i])) {
                        st.pop();
                    }
                    if (!st.empty() && st.top() == abs(nums[i])) {
                        st.pop();
                    } else {
                        if (st.empty() || st.top() < 0) {
                            st.push(nums[i]);
                        }
                    }
                } else {
                    st.push(nums[i]);
                }
            } else {
                st.push(nums[i]);
            }
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        
        return res;
    }
};
