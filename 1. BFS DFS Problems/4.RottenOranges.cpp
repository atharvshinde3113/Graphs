int orangesRotting(vector<vector<int>>& grid) {
    int ans = -1, fresh = 0, m = grid.size(), n = grid[0].size();

    queue<pair<int, int>> q; //row,col for traversal

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});   //find+store the starting pts for traversal
            } 
            if(grid[i][j] == 1) {
                fresh++; //no of fresh oranges
            }
        }
    }

    if(fresh == 0) {
        return 0;
    }

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
                    grid[newrow][newcol] = 2;
                    q.push({newrow, newcol});
                    fresh--;
                }
            }
        }
        ans++;
    }

    if (fresh > 0) return -1;
    else return ans;
}

/* 
If no while(siz--) is written:

writing while(siz--) increments ans once per level, which correctly tracks the minutes passed.

Not writing it increments ans for each orange processed, which incorrectly tracks the total number of oranges processed instead of the time

Time Complexity: O(m * n) - where 'm' is the number of rows and 'n' is the number of columns in the grid.
Space Complexity: O(m * n) - due to the queue and the grid.

/*