#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

bool visited[5][5];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool bfs(int x, int y, vector<string> v) {
    
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()) {
        
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || v[nx][ny] == 'X')
                continue;
            
            if(abs(x-nx) + abs(y-ny) > 2)
                continue;
            
            if(v[nx][ny] == 'P')
                return false;
            
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    return true;   
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer = {1, 1, 1, 1, 1};
    
    for(int i = 0; i < places.size(); i++) {
        memset(visited, 0, sizeof(visited));
        vector<string> p = places[i];
        
        for(int j = 0; j < places[i].size(); j++) {
            for(int k = 0; k < places[i][j].size(); k++) {
                if(places[i][j][k] == 'P') {
                    if(!bfs(j, k, p)) {
                        answer[i] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return answer;
}