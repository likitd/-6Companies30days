class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t = 0;
        vector<vector<int>> ans = grid;
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        
        // Push all initially rotten oranges into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 2;
                }
            }
        }

        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        
        // Perform BFS to rot adjacent oranges
        while (!q.empty()) {
            auto curr = q.front();
            int r = curr.first.first;
            int s = curr.first.second;
            t = curr.second;
            
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int ns = s + delcol[i];

                if (nr >= 0 && nr < grid.size() && ns >= 0 && ns < grid[0].size() && grid[nr][ns] == 1 && ans[nr][ns] != 2) {
                    q.push({{nr, ns}, t + 1});
                    ans[nr][ns] = 2;
                }
            }
        }

        // Check if any fresh orange is left unrotten
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && ans[i][j] != 2) {
                    return -1;
                }
            }
        }

        return t;
    }
};