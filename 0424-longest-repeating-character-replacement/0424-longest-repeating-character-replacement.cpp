class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0;
        int r=0;
        int maxFreq=0;
        int ans = -1;
    unordered_map<char , int>mp;
    while(r<n){
        mp[s[r]]++;

        maxFreq= max(maxFreq , mp[s[r]]);

        int curr_len= r-l+1;
        if(curr_len-maxFreq >k)
        {
            mp[s[l]]--;
            l++;
        }
        curr_len = r-l+1;
        ans = max(ans , curr_len);
        r++;
    }
    return ans;
    }
};