#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[101];

int cntNetwork(int tower) {
    
    bool visited[101] = {false};
    queue<int> q;
    q.push(tower);
    visited[tower] = true;
    int cnt = 0;
    
    while(!q.empty()) {
        
        int cur = q.front();
        q.pop();
        cnt++;
        
        for(int i = 0; i < v[cur].size(); i++) {
            if(visited[v[cur][i]])
                continue;
            
            q.push(v[cur][i]);
            visited[v[cur][i]] = true;            
        }
    }
    
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for(int i = 0; i < wires.size(); i++) {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);            
    }
    
    for(int i = 0; i < wires.size(); i++) {
        int left = wires[i][0];
        int right = wires[i][1];
        
        v[left].erase(remove(v[left].begin(), v[left].end(), right), v[left].end());
        v[right].erase(remove(v[right].begin(), v[right].end(), left), v[right].end());
        
        answer = min(answer, abs(cntNetwork(left) - cntNetwork(right)));
        
        v[left].push_back(right);
        v[right].push_back(left);        
    }
    
    return answer;
}