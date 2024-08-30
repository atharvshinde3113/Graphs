//BFS
bool bfs(int src, vector<int> adj[], int vis[]){
	vis[src] = 1;
	queue<pair<int,int>> q; //node,parent
	q.push({src,-1});
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto adjacentNode: adj[node]){
			if(!vis[adjacentNode]){
				vis[adjacentNode]=1;
				q.push({adjacentNode,node});
			}
			else if(parent!=adjacentNode){ //adjacentNode is visited but it isnt the parent
				return true;
			}
		}
	}
	return false;
}

bool detect(int V, vector<int> adj[]){
	int vis[V] = {0};
	for (int i = 0; i < V; ++i)
	{
		if(!vis[i]){
			if(detect(i,adj,vis)) return true;
		}
	}
	return false;
}


//Alt BFS w/o storing parent:

// A particular node can be marked visited only by its parent so when we reach a node and traverse all its adjacent node and find more than one visited ,that shows this node has more than one parent or we can simply say this particular node is also getting visited from another direction and in that case we can say there is cycle present.
 bool bfs(int node,vector<int> &vis, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node]=1;
       while(!q.empty()){
          int frnt= q.front();
          q.pop();
          int cnt=0;
          for(auto it:adj[frnt]){
              if(!vis[it]){
                  q.push(it);
                  vis[it]=1;
              }
              else {
                  cnt++;
              }
          }
          if(cnt>1) return true;
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj)) return true;
            }
        }
        return false;
    }
};
//DFS


bool dfs(int node,int parent, vector<int> adj[], int vis[]){
	vis[src]=1;
	for (auto adjacentNode: adj[node])
	{
		if(!vis[adjacentNode]){
			if(dfs(adjacentNode,node,adj,vis)){
				return true;
			}
		}
		else if(parent!=adjacentNode){
			return true;
		}
	}
	return false;
}

bool isCycle(int V, vector<int> adj[]){
	int vis[V] = {0};
	for (int i = 0; i < V; ++i){}
		if(!vis[i]){
			if(dfs(i,-1,adj,vis)) return true;
		}

	}
	return false;

	//in case of 1 component : return dfs(1,-1,vis,adj);
}