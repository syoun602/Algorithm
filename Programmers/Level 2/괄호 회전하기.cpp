#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool checkString(string s) {
    
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if(s[i] == ')' && st.top() == '(')
                st.pop();
            else if(s[i] == ']' && st.top() == '[')
                st.pop();
            else if(s[i] == '}' && st.top() == '{')
                st.pop();
            else
                return false;
        }
    }
    
    if(!st.empty())
        return false;
    
    return true;    
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(checkString(s))
            answer++;
        
        s += s[0];
        s.erase(s.begin());
    }
    return answer;
}