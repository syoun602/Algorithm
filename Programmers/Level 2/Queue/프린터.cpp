#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++)
        q.push({i, priorities[i]});
    
    sort(priorities.begin(), priorities.end(), greater<>());
        
    while(!q.empty()) {       
        if(q.front().second == priorities[answer-1]) {
            if(location == q.front().first)
                return answer;
            q.pop();
            answer++;
        }
        else {
            q.push(q.front());
            q.pop();
        }        
        
    }
}