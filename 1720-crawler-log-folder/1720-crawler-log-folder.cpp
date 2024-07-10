class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>s;
        int n = logs.size();

        for(auto log : logs){
             if(log=="../") {
                if(!s.empty()) s.pop();
             }
             else if(log!="./")  s.push(log);;

            
        }
        return s.size();
    }
};