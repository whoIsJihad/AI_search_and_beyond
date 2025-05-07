#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,
         pair<int, int> source)
{
    queue<pair<int, int>> q;
    visited[source.first][source.second] = true;
    q.push(source);

    while (!q.empty())
    {

        std::pair<int, int> topc = q.front();
        q.pop();

        std::vector<int> dx = {-1, 1, 0, 0};
        std::vector<int> dy = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int new_x = topc.first + dx[i];
            int new_y = topc.second + dy[i];
            bool valid =
                (new_x >= 0 && new_x < grid.size()) && (new_y >= 0 && new_y < grid[0].size());
            if (valid && grid[new_x][new_y] == 1 &&!visited[new_x][new_y])
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
            }
        }
    }
}
int numIslands(vector<vector<int>> &grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int cnt = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == false)
            {
                cnt++;
                bfs(grid, visited, {i, j});
            }
        }
    }
    return cnt;
}

int main(){
    int m,n;
    freopen("number_of_island.txt","r",stdin);
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    forn(i,m){
        forn(j,n){
            cin>>grid[i][j];
        }
    }

    cout<<numIslands(grid)<<endl;
}