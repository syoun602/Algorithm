#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for(int i = 1; i <= s.length()/2; i++) {

        int cnt = 1;
        string output = "";
        string match = s.substr(0,i);

        for(int j = i; j <= s.length(); j = j + i) {
            string cur = s.substr(j,i);
            if(match == cur)
                cnt++;
            else { 
                if(cnt > 1) {
                    output += to_string(cnt) + match;
                    cnt = 1;
                }
                else
                    output += match;  

                match = cur;
            } 
            
            if(j+i > s.length()) {
                output += s.substr(j);
                break;
            }
        }

        answer = min(answer, (int)output.length());
    }

    return answer;
}