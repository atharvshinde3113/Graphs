void dfs(int node, vector<int> adj[], vector<int>& ans, vector<int>& vis){
    ans.push_back(node);
    vis[node] = true;
    for(auto it : adj[node]){ // go through the entire neighbours of the node
        if(!vis[it])
            dfs(it, adj, ans, vis);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V, 0);
    dfs(0, adj, ans, vis);
    return ans;
}


//adj[1] = adjacency list of 1 i.e nodes that are neighbours of 1.


//O(N + E) TC O(N) SC for vis vector   N Nodes E Edges


for (int i = 0; i < n; ++i)
{
    if(!vis[i]){
        //code
        dfs(i,adj,vis);
    }
}

//Matrix DFS
void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis) {
        vis[i][j] = 1; //mark visited

        int row = grid.size();
        int col = grid[0].size();

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newrow = i + delrow[k];
            int newcol = j + delcol[k];

            if (newrow >= 0 && newrow < row && newcol >= 0 && newcol < col && 
                grid[newrow][newcol] == '1' && !vis[newrow][newcol]) {
                dfs(grid, newrow, newcol, vis);
            }
        }
}