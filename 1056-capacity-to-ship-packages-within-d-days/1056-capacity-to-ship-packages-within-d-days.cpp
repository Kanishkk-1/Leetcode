int noOfDays(vector<int>& v, int capacity){
    int n=v.size();
    int days=0;
    int load=0;
    for(int i=0;i<n;i++){
        if(load+v[i]>capacity){
             days++;
             load=v[i];
        }
        else{
            load+=v[i];
        }
    }
    return days;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, weights[i]);}
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int noofdays = noOfDays(weights, mid);
            if(noofdays<days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};