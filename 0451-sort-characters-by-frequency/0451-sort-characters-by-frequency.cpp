class Solution {
public:
    string frequencySort(string s) {
              unordered_map<char, int> mp;
        for (auto a : s) {
            mp[a]++;
        }

        
        multimap<int, char> r;
        for (auto a : mp) {
            r.insert({a.second, a.first});
        }

        
        string ss = "";
        for (auto it = r.rbegin(); it != r.rend(); ++it) {
       
            ss += string(it->first, it->second);
        }

        return ss;
    }
};