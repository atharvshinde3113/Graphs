//TC O(NxM) X 4 as youre calling it 4 times for neigbours
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image,int newColor,int initial_color, int delrow[], int delcol[]){
    ans[row][col] = newColor;
    int n=image.size();
    int m = image[0].size();
    for(int k=0;k<4;k++){
        int newrow=row+delrow[k];
        int newcol=col+delcol[k];

        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && image[newrow][newcol]==initial_color &&ans[newrow][newcol]!=newColor //i.e !vis[]){ 
            dfs(newrow,newcol,ans,image,newColor,initial_color,delrow, delcol);  
        }
    }


}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        dfs(sr,sc,ans,image,color,initial_color,delrow, delcol);
        return ans;
    }
};


-------------
bfs:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans(image.begin(), image.end());
    int m = image.size(), n = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int s = ans[sr][sc];
    ans[sr][sc] = color;

    vector<int> delrow = {-1, 1, 0, 0};
    vector<int> delcol = {0, 0, -1, 1};

    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {       //for (i=0->q.size()) i.e for(auto it: adj[node]) //not req here as its adjacency list itself are the 4 directions dentoed by lower loop BUT STILL WRITE IT AS NOT WRITING IT MAY RESULT IN ERRORS IN OTHER CASES

            auto p = q.front();
            q.pop();

            int row = p.first; 
            int col = p.second;

            for (int i = 0; i < 4; i++) {
                int newrow = row + delrowow[i]; 
                int newcol = col + delcol[i];

                if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && ans[newrow][newcol] == s && ans[newrow][newcol] != color) {
                    ans[newrow][newcol] = color;
                    q.push({newrow, newcol});
                }
            }
        }
    }

    return ans;
}
