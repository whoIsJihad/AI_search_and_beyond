#include <iostream>
#include <vector>
#include <queue>


#define for(i, n) for (int i = 0; i < n; i++)

int solve(int m, int n)
{
    std::vector<std::vector<int>> board(m, std::vector<int>(n));
    std::vector<std::vector<int>> cost(m, std::vector<int>(n,-1));
    for (i, m)
    {
        for (j, n)
        {
            std::cin >> board[i][j];
        }
    }
    std::queue<std::pair<int, int>> q;
    cost[0][0]=0;
    q.push({0, 0});

    while (!q.empty())
    {
       
        std::pair<int, int> topc = q.front();
        q.pop();
        if(topc.first==m-1 && topc.second==n-1){
            return cost[topc.first][topc.second];
        }
        std::vector<int> dx = {-1, 1, 0, 0};
        std::vector<int> dy = {0, 0, 1, -1};
        for (i, 4)
        {
            int new_x = topc.first + dx[i];
            int new_y = topc.second + dy[i];
            bool valid=(new_x>=0 && new_x<m)&&(new_y>=0 && new_y<n);
            if(valid && !board[new_x][new_y]){
                q.push({new_x,new_y});
                cost[new_x][new_y]=cost[topc.first][topc.second]+1;
            }
        }       
    }
    return -1;
}

int main()
{
    freopen("shortest_path_in_grid.txt","r",stdin);
    std::cout<<solve(5,8)<<std::endl;;
    return 0;
}