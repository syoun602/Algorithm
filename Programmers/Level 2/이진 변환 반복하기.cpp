#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_binary(int n) {
    
    string s = "";
    
    while(n != 0) {
        if(n % 2 == 1)
            s = "1" + s;
        else
            s = "0" + s;
        
        n /= 2;
    }
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    while(s != "1") {
        int num = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1')
                num++;
        }
        
        answer[0]++;
        answer[1] += (s.size() - num);
        s = to_binary(num);
    }
    
    return answer;
}