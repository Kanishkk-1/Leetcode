class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        long long ans=0;
        
        for(auto & i:gifts){
            pq.push(i);
        }

        while(k--){
          long long n = sqrt(pq.top());
            pq.pop();
            pq.push(n);
        }

        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};