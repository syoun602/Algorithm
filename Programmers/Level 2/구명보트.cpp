#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int cnt = 0, idx = 0;

    sort(people.begin(), people.end(), greater<>());
    
    while(idx < people.size()) {
        if(people[idx++] + people.back() <= limit) {
            answer++;
            people.pop_back();
        }
        else {
            answer++;
        }
    }
    
    return answer;
}