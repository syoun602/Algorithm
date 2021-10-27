#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++) {
        int cnt = 0;
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];
            cnt++;
        }
        q.push(cnt);
    }
    
    int day, jobs = 0;
    
    while(!q.empty()) {
        if(jobs == 0) {
            day = q.front();
            jobs = 1;
        }
        else if(q.front() > day) {
            answer.push_back(jobs);
            day = q.front();
            jobs = 1;
        }
        else
            jobs++;
        
        q.pop();
    }
    
    if(jobs > 0)
        answer.push_back(jobs);
    
    return answer;
}