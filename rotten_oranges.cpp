#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

int solve(vector<vector<int>> &grid)
{
    int max_time=0;
    vector<pair<int, int>> rotten_oranges;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> min_time(m, vector<int>(n, INT_MAX));
    // vector<vector<int>>visited(m,vector<int>(n,0));

    forn(i, m)
    {
        forn(j, n)
        {
            if (grid[i][j] == 2)
                rotten_oranges.push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    forn(i, rotten_oranges.size())
    {
        pair<int, int> temp = rotten_oranges[i];
        min_time[temp.first][temp.second] = 0;

        q.push(temp);
    }

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        forn(i, 4)
        {
            int nx = temp.first + dx[i];
            int ny = temp.second + dy[i];
            bool valid = (nx >= 0) && (nx <= m-1) && (ny >= 0) && (ny <= n-1);
            if (valid && grid[nx][ny] == 1)
            {
                // cout<<"Rotting orange at "<<nx<<" , "<<ny<<endl;
                grid[nx][ny] = 2;
                min_time[nx][ny] = min_time[temp.first][temp.second] + 1;
                max_time=max(max_time,min_time[nx][ny]);
                q.push({nx, ny});
            }
        }

    }

    forn(i,m){
        forn(j,n){
            if(grid[i][j]==1)return -1;
        }
    }
    return max_time;
}
int main()
{
    freopen("rotten_oranges.txt","r",stdin);
    int m,n;

    cin>>m>>n;
    vector<vector<int>>grid( m, vector<int>(n));
    forn(i,m){
        forn(j,n){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid)<<endl;
}