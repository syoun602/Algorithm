#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    int turn = size - 1;
    for (int i = 0; i < name.size(); i++) {
        answer += min(name[i] - 'A', 26 - (name[i] - 'A'));

        int idx = i + 1;
        while (idx < name.size() && name[idx] == 'A')
            idx++;

        turn = min(turn, i + size - idx + min(i, size - idx));
    }
    answer += turn;
    
    return answer;
}