#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[8];
vector<vector<int>> dungeon;
int answer = 0;

void dfs(int health, vector<vector<int>> &d) {
    
    if(d.size() == dungeon.size()) {
        int cnt = 0;
        
        for(int i = 0; i < d.size(); i++) {
            if(health >= d[i][0]) {
                health -= d[i][1];
                cnt++;
            }
        }
        answer = max(answer, cnt);
    
    }
    
    for(int i = 0; i < dungeon.size(); i++) {
        if(visited[i])
            continue;
        
        vector<int> v = dungeon[i];
        visited[i] = true;
        d.push_back(v);
        dfs(health, d);
        visited[i] = false;
        d.pop_back();
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    dungeon = dungeons;
    vector<vector<int>> empty;
    
    dfs(k, empty);
    
    return answer;
}