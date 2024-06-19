// level wise traversal

for (int i = 0; i < n; ++i)
{
	if(!vis[i]){
		bfs(i);
	}
}


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

		if(auto it : adj[node]){ //it now traverses over adj list of the node
			if(!vis[it]){  //see if neighbours are visited
				vis[it] = 1;  // if no, visit them 
				q.push(it); // taken into bfs for next step
			}
		}
	}
	return bfs;


}