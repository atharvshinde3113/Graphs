void dfs(int node, vector<int> adj[], vector<int>& ans, vector<int>& vis){
    ans.push_back(node);
    vis[node] = true;
    for(auto i : adj[node]){ // go through the entire neighbours of the node
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


//adj[1] = adjacency list of 1 i.e nodes that are neighbours of 1.


//O(N + E) TC O(N) SC for vis vector   N Nodes E Edges