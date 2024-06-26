class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int openParentheses = 0;
        for(auto c : s){
            if(c == '('){
                if(openParentheses > 0){
                    ans += c;
                }
                openParentheses++;
            }
            else if(c == ')'){
                if(openParentheses > 1){
                    ans += c;
                }
                openParentheses--;
            }
        }
        return ans;
    }
};