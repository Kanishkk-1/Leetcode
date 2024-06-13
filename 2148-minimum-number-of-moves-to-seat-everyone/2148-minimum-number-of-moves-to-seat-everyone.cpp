#include <cstdlib>

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        int ans = 0;
        int n = students.size();
        for(int i=0;i<n;i++){
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};