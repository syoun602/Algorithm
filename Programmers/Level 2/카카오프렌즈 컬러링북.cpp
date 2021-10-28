#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int number_of_area = 0;
int max_size_of_one_area = 0; 
vector<vector<int>> pic;
int visited[100][100];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int x, int y, int m, int n) {

    if(visited[x][y])
        return;

    queue<pair<int, int>> q;
    q.push({x, y});
    number_of_area++;
    visited[x][y] = 1;
    int cnt = 1;

    while(!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                continue;

            if(pic[x][y] == pic[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                cnt++;
            }
        }
    }

    max_size_of_one_area = max(max_size_of_one_area, cnt);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    pic = picture;
    memset(visited, 0, sizeof(visited));
    number_of_area = 0;
    max_size_of_one_area = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(pic[i][j] != 0)
                bfs(i, j, m, n);
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}