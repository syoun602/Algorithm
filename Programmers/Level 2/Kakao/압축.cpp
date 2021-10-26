#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dictionary;
    
    for(int i = 0; i < 26; i++) {
        string s;
        s.push_back(i+65);
        dictionary.push_back(s);
    }
    
    int index;
    string s = ""; 
    
    for(int i = 0; i < msg.length(); ++i) {
        s.push_back(msg[i]);
        auto iter = find(dictionary.begin(), dictionary.end(), s);
        if(iter != dictionary.end()){
            index = iter-dictionary.begin();
            if(i == msg.length()-1)
                answer.push_back(index+1);
        }
        else {
            dictionary.push_back(s);
            answer.push_back(index+1);
            i--;
            s = "";
        }
    }
    
    return answer;
}