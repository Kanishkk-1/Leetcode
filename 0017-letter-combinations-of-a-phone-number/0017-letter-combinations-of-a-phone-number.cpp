class Solution {
public:
void letterCombo(int ind ,  vector<string>& pad , string digits , vector<string>&v  , string temp ){
     if(ind==digits.size()){
       v.push_back(temp);
       return;
     }


        string value = pad[digits[ind] - '0'];
        for (int i = 0; i < value.size(); i++) {
            temp.push_back(value[i]);
           letterCombo( ind+1 ,   pad , digits , v  , temp );
            temp.pop_back();
        }

}



public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) {
            return {};
        }
          vector<string> pad = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };
    string temp;
       vector<string>v;
       letterCombo(0, pad , digits , v , temp);
       return v;
    }
};