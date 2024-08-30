

void dfs(int node, vector<int> adj[], vector<bool>& vis){
    vis[node] = true;
    for(auto v : adj[node]){
        if(!vis[v])
            dfs(v, adj, vis);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    // Convert isConnected matrix into adjacency list
    vector<int> adj[n]; //adj list
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isConnected[i][j] == 1 && i!=j){
                adj[i].push_back(j);
                // no need of writing adj[j].push_back(i) as outer loop covers it.
            }
        }
    }
    
    vector<bool> vis(n, false);
    
    // Perform DFS to find the number of provinces
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cnt++; //if it hasnt been previously visited = unique connected comp
            dfs(i, adj, vis);
        }
    }

    return cnt;
}
