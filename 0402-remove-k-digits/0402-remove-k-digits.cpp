
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char digit : num) {
            while (!st.empty() && st.top() > digit && k) {
                st.pop();
                k--;
            }
            if (!st.empty() || digit != '0') {  // Avoid leading zeros
                st.push(digit);
            }
        }

        // If k is still greater than 0, remove the remaining digits from the end
        while (!st.empty() && k) {
            st.pop();
            k--;
        }

        // Construct the result string from the stack
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());  // Since we used a stack, the order is reversed

        // Edge case for empty result
        if (result.empty()) {
            return "0";
        }

        return result;
    }
};