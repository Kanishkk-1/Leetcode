class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<int>set;
        int maxi = INT_MIN;
        int l =0;
        int n = s.size();
        for(int r=0;r<n;r++){
             if (set.find(s[r]) != set.end()){
            while(l<r && set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
             }
            set.insert(s[r]);
            maxi = max(maxi , r-l+1);

        }
        return maxi;
    }
};