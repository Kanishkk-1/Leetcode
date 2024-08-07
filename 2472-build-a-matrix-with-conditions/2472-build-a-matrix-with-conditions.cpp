class Solution {
public:

    bool toposort(vector<vector<int>> &adj, vector<int> &tsort, vector<int> &ind)
    {
        int V = ind.size();
        queue<int> q;
        
        for(int i=0 ; i<V ; i++) if(ind[i] == 0) q.push(i);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            tsort.push_back(u);

            for(auto &v: adj[u])
            {
                ind[v] -= 1;
                if(ind[v] == 0) q.push(v);
            }
        }

        if(tsort.size() != V) return false;
        return true;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> adj_row(k, vector<int> ());
        vector<vector<int>> adj_col(k, vector<int> ());

        vector<int> ind_row(k, 0);
        vector<int> ind_col(k, 0);

        for(auto &edge: rowConditions) 
        {
            adj_row[edge[0]-1].push_back(edge[1]-1);
            ind_row[edge[1]-1] += 1;
        }

        for(auto &edge: colConditions) 
        {
            adj_col[edge[0]-1].push_back(edge[1]-1);
            ind_col[edge[1]-1] += 1;
        }
        
        vector<int> tsort_row;
        vector<int> tsort_col;

        bool notCycle_row = toposort(adj_row, tsort_row, ind_row);
        bool notCycle_col = toposort(adj_col, tsort_col, ind_col);

        if(!notCycle_row || !notCycle_col) return {};
        vector<vector<int>> ans(k, vector<int> (k, 0));

        for(int row = 0 ; row < k ; row++)
        {
            int col = find(tsort_col.begin(), tsort_col.end(), tsort_row[row]) - tsort_col.begin();
            ans[row][col] = tsort_row[row]+1;
        }

        return ans;
    }
};