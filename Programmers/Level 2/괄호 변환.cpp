#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string s) {
    int close_cnt = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            close_cnt++;
        else
            close_cnt--;
        
        if(close_cnt < 0)
            return false;
    }
    
    return true;
}

string solution(string p) {
    
    string answer = "";
    string u, v;
    int left = 0, right = 0;

    if(p == "")
        return "";
    
    for(int i = 0; i < p.size(); i++) {
        if(p[i] == '(')
            left++;
        else if(p[i] == ')')
            right++;

        if(left == right) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(check(u)){
        answer += u + solution(v);
    }
    else {
        answer += "(" + solution(v) + ")";
        
        for(int i = 1; i < u.size()-1; i++)
            answer += u[i] == '(' ? ")" : "(";
    }
    
    return answer;    
}