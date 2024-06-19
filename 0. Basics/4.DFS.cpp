void dfs(int node, vector<int> adj[], vector<int>& ans, vector<int>& vis){
    ans.push_back(node);
    vis[node] = true;
    for(auto i : adj[node]){ // go through the entire adj list 
        if(!vis[i])
            dfs(i, adj, ans, vis);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V, 0);
    dfs(0, adj, ans, vis);
    return ans;
}
