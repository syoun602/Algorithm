#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<string> ID;    
    
    for(int i = 0; i < record.size(); i++) { 
        string type, id, name;
        stringstream ss;
        ss.str(record[i]);
        ss >> type;
        
        if(type == "Enter") {
            ss >> id;
            ss >> name;
            m[id] = name;
            ID.push_back(id);
            answer.push_back("님이 들어왔습니다.");
        }
        else if(type == "Leave") {
            ss >> id;
            ID.push_back(id);
            answer.push_back("님이 나갔습니다.");
        }
        else {
            ss >> id;
            ss >> name;
            m[id] = name;
        }
    }    
    
    for(int i = 0; i < answer.size(); i++){
        answer[i] = m[ID[i]] + answer[i];
    }
    
    return answer;
}