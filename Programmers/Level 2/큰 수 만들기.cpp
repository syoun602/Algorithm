#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int idx = -1;
    for(int i = 0; i < number.size() - k; i++) {
        char max_c = 0;
        
        for(int j = idx + 1; j <= k + i; j++) {
            if(max_c < number[j]) {
                max_c = number[j];
                idx = j;
            }
        }
        answer += max_c;
    }
    
    return answer;
}