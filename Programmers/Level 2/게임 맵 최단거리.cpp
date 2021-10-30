#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int x, int y) {
    
    
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    bfs(0, 0);
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();      
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(maps[nx][ny] == 1) {
                maps[nx][ny] += maps[cur.first][cur.second];
                q.push({nx, ny});
            }
        }
    }
    
    if(maps[n-1][m-1] == 1)
        return -1;
    
    return maps[n-1][m-1];
}