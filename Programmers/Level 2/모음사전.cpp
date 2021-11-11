#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> v = {"A", "E", "I", "O", "U"};
vector<string> dic;

void dfs(string str) {
    
    if(str.size() > 5)
        return;
    
    dic.push_back(str);
    
    for(int i = 0; i < v.size(); i++) {
        dfs(str + v[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    for(int i = 0; i < v.size(); i++)
        dfs(v[i]);
    
    
    for(int i = 0; i < dic.size(); i++)
        if(dic[i] == word)
            answer = i + 1;
    
    return answer;
}