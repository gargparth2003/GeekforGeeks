


class Solution {
  public:
    int x[4]={-1, 0, 1, 0};
    int y[4]={0, 1, 0, -1};
    void grouper(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m, int group, int& size){
        if(i==n || i<0 || j==m || j<0 || vis[i][j]!=-1 || grid[i][j]==0){
            return;
        }
        vis[i][j]=group;
        size++;
        for(int k=0; k<4; ++k){
            int new_i=i+x[k];
            int new_j=j+y[k];
            grouper(grid, vis, new_i, new_j, n, m, group, size);
        }
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int maxSize=0, tempSize=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int size, group=0;
        unordered_map<int, int> mp;
        unordered_set<int> set;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    size=0;
                    grouper(grid, vis, i, j, n, m, group, size);
                    mp[group]=size;
                    maxSize=max(maxSize, size);
                    group++;
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==0){
                    tempSize=0;
                    for(int k=0; k<4; ++k){
                        int new_i=i+x[k];
                        int new_j=j+y[k];
                        if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && vis[new_i][new_j]!=-1 && !set.count(vis[new_i][new_j])){
                            tempSize+=mp[vis[new_i][new_j]];
                            set.insert(vis[new_i][new_j]);
                        }
                    }
                    maxSize=max(maxSize, tempSize+1);
                    set.clear();
                }
            }
        }
        return maxSize;
        
        
    }
};


// link
//You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent to each other and both have the same value.

// Examples :

// Input: grid = [1, 1]
//              [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]
// Input: grid = [1, 0, 1]
//              [1, 0, 1]
//              [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= size of the grid<= 500
// 0 <= grid[i][j] <= 1

