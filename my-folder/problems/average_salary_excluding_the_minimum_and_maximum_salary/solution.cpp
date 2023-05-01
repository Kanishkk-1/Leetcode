class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(), s.end());
        double sum =0;
        double avg = 0.00000;
        int n = s.size();
        for(int i=1; i<n-1; i++){
           sum += s[i];
        }
         avg= sum/(n-2);
        return avg;
    }
};


