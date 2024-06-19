// Input given: 1 st line has n and m -> nodes and edges.
// Next m lines have pair of numbers which represent 2 connected nodes

 
//Adjacency matrix  SC = O(N^2)
int main(){ 
	int n,m; //nodes and edges
	cin>>n>>m;
	int adj[n+1][n+1]; //graph is stored here
	for (int i = 0; i < m; ++i)
	{ 
		int u,v; // connected nodes u and v 
		cin>>v>>u;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	return 0;
}

// Adjacency List SC=O(2xE for undirected, E for directed)

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];  // an array adj created containing n+1 vectors
	for (int i = 0; i < m; ++i)
	{
		int u,v; // u--->v 
		cin>>u>>v;
		adj[u].push_back(v); 
		adj[v].push_back(u); // Not required in case of directed graph 
	}
}

// Weighted graphs:

int main(){ 
	int n,m; //nodes and edges
	cin>>n>>m;
	int adj[n+1][n+1]; //graph is stored here
	for (int i = 0; i < m; ++i)
	{ 
		int u,v,wt; // connected nodes u and v 
		cin>>v>>u>>wt;
		adj[u][v]=wt;
		adj[v][u]=wt; //omit this line if its an undirected graph
	}
	return 0;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> adj[n+1];   
	for (int i = 0; i < m; ++i)
	{
		int u,v,wt; // u--->v 
		cin>>u>>v>>wt;
		adj[u].push_back{v,wt}; 
		adj[v].push_back{u,wt}; // Not required in case of directed graph 
	}
}