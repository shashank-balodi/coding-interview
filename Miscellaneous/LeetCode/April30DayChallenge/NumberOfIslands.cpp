#include<bits/stdc++.h>

class Solution {
public:
    void travel_island(std::vector<std::vector<char>>& grid, int r, int c,std::vector<std::vector<int>>& visited) {
        visited[r][c] = true;
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++) {
            if(r + row[i] < grid.size() && c + col[i] < grid[0].size() && !visited[r + row[i]][c + col[i]] && grid[r + row[i]][c + col[i]] == '1') {
                travel_island(grid, r + row[i], c + col[i], visited);
            }
        }
    }
    
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        std::vector<std::vector<int>> visited;
        
        for(int i = 0; i < grid.size(); i++) {
            std::vector<int> a;
            for(int j = 0; j < grid[i].size(); j++) {  
                a.push_back(0);
            }
            visited.push_back(a);
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    travel_island(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};