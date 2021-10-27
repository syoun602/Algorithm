#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m[11];
int MaxCnt[11] = {0};

void combi(string o, int pos, string menu) {
    
    if(pos >= o.length()) {
        int len = menu.length();
        if(len >= 2) {
            m[len][menu]++;
            MaxCnt[len] = max(MaxCnt[len], m[len][menu]);
        }
        return;
    }
    combi(o, pos+1, menu + o[pos]);
    combi(o, pos+1, menu);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto o : orders) {
        sort(o.begin(), o.end());
        combi(o, 0, "");
    }
    
    for(auto c : course) {
        for(auto item : m[c]) {
            if(item.second >= 2 && item.second == MaxCnt[c]) {
                answer.push_back(item.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}