#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[200];

void dfs(int net, int n, vector<vector<int>>& computers) {
    
    visited[net] = true;
    
    for(int i = 0; i < n; i++) {
        if(computers[net][i] && !visited[i])
            dfs(i, n, computers);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
            
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            dfs(i, n, computers);
        }
    }
    
    return answer;
}