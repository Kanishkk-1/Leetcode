class Solution {
private:
    void dfs(int node, vector<int> adjls[], vector<int>&vis) {
        vis[node] = 1;
        for (auto i : adjls[node])
            if (!vis[i]) {
                dfs(i, adjls, vis);
            }
    }

public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> adjls[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        // int vis[n] = {0};
        vector<int>vis(n , 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjls, vis);
            }
        }
        return cnt;
    }
};