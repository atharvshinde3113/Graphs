// level wise traversal
// there can only be 1 node at level 0
// BFS depends on starting node. Move by 1 place breadthwise across all directions per level
// O(N) outer while + O(2xEdges) inside for loop that runs for total degrees TC  
// O(3N) SC

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	int vis[V] = {0};
	vector<int> bfs;
	queue<int> q;

	//first node
	vis[0]=1;
	q.push(0);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		bfs.push_back(node);
		//For each adjacent vertex of the current node, if it has not been visited, we push it into the queue and mark it as visited.

		if(auto it : adj[node]){ //it now traverses over adj list of the node
			if(!vis[it]){  //see if neighbours are visited
				vis[it] = 1;  // if no, visit them 
				q.push(it); // taken into bfs for next step
			}
		}

		// if(auto adjacentNode : adj[node]){ //it now traverses over adj list of the node
		// 	if(!vis[adjacentNode]){  //see if neighbours are visited
		// 		vis[adjacentNode] = 1;  // if no, visit them 
		// 		q.push(adjacentNode); // taken into bfs for next step
		// 	}
		// }		
	}
	return bfs;


}

--------------
if(!vis[node]){
	bfs(node)
}



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


--------
BFS for a matrix

    int m = grid.size(), n = grid[0].size();

    queue<pair<int, int>> q; //row,col for traversal

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                q.push({i, j});   //find+store the starting pts for traversal
            } 
        }
    }
    int no_of_levels=0;
    vector<int> delrow = {-1, 1, 0, 0};
    vector<int> delcol = {0, 0, -1, 1};

    while(!q.empty()) {
        int k = q.size();
        while(k--) {
            auto p = q.front();
            q.pop();
            int row = p.first; 
            int col = p.second;

            for(int i = 0; i < 4; i++) {
                int newrow = row + delrow[i]; 
                int newcol = col + delcol[i];
                if(newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && grid[newrow][newcol] == 1) {
                    grid[newrow][newcol] = 2; // mark visited
                    q.push({newrow, newcol}); // next traversal
                }
            }
        }
        no_of_levels++;
    }
