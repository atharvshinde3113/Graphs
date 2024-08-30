/*
1-Land 0-Water


traverse through the entire matrix, to find starting pts for BFS. A point is a starting point if its land. Start the BFS from that point. a pt now is denoted by {row,col} so a 2D vis array is required. 

Put the starting pt in queue. Now generally we used to go through adj list of the starting pt to perform bfs on them. no need here as we know who the neighbours of a specific node are {N,S,W,E,NE,NW,SE,SW}. so perform bfs on them.

The queue becomes empty once every node of the island is visited as the last node's neighbours are either 0 or already visited

*/ 
void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis)
    {
    vis[i][j]=1;

    int row=grid.size();
    int col=grid[0].size();

    queue<pair<int,int>>q;
    q.push({i,j});

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
        int newrow=r+delrow[k];
        int newcol=c+delcol[k];

        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]=='1' &&       !vis[newrow][newcol])
        {
            vis[newrow][newcol]=1;
            q.push({newrow,newcol});
        }
        }
        
    }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); //no of row
        int m=grid[0].size();//no of col

        vector<vector<int>>vis(n,vector<int>(m,0)); //2D vector named vis with n rows and m columns, where each element is initialized to 0.
        // basically n vectors of m size all initialized to zero.
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }


-------------
void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis) {
        vis[i][j] = 1;

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
