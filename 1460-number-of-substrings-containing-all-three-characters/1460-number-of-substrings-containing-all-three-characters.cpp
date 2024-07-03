class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r =0;
        int n= s.size();
        int cnt =0;
        unordered_map<char , int > mp;
        while(r<n){
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                cnt += (n-r);
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};