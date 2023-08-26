class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);

        int count=0;
        int second=INT_MIN;
        for(auto it:pairs){
            if(second<it[0]){
                count++;
                second=it[1];
            }
        }
        return count;
    }
};