class MyComp
{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            if(a.first==b.first)
            {
                return a.second < b.second;
            }
            return a.first > b.first;

        }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyComp>pq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
                pq.push({it->second,it->first});
        }
        while(!pq.empty())
        {
            int freq=pq.top().first;
            int el=pq.top().second;
            pq.pop();
            for(int i=0;i<freq;i++)
            {
                ans.push_back(el);
            }
        }
        return ans;
    }
};