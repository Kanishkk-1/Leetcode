class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalwt=0;
        int ct = 0;
        for(auto i : customers){
            int arrtime = i[0];
            int cooktime = i[1];

            if(arrtime>ct) ct = arrtime;

           totalwt += ct+cooktime -arrtime;
           ct+=cooktime;
        }
        int n = customers.size();
        return (double)totalwt/n;
    }
};