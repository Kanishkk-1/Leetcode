class Solution {
public:
    string reverseParentheses(string s) {
    string res;
    stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=')')
            {
                st.push(s[i]);
            }
            else
            {
                res="";
                while(!st.empty() && st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<res.length();j++)
                    st.push(res[j]);
            }
        }
        res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};