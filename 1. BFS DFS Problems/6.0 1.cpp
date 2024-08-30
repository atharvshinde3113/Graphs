vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(); 
    int n = mat[0].size();
    vector<vector<int>> dis(m, vector<int>(n, -1)); //dis 2d vector of same size with -1 initialized.
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                dis[i][j] = 0;
                q.push({i, j});//starting pts for bfs
            }
        }
    }

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    int level = 1;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int nx = x + dr[i], ny = y + dc[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && dis[nx][ny] == -1){ //i.e unvisited
                    dis[nx][ny] = level;
                    q.push({nx, ny});
                }
            }
        }
        level++;
    }

    return dis;
}
