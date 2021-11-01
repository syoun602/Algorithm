#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> scores;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> applicant;
    vector<vector<string>> want;
    
    for(auto in : info) {
        string s[4];      
        int score;
        istringstream stt(in);
        stt >> s[0] >> s[1] >> s[2] >> s[3] >> score;
        
        for(int i = 0; i < 16; i++) {
            string str = "";
            int cnt = i;
            for(int j = 3; j >= 0; j--) {
                if(cnt <= 0 || cnt % 2 == 0)
                    str = '-' + str;
                else
                    str = s[j] + str;
                cnt /= 2;
            }
            
            scores[str].push_back(score);
        }
    }
    
    for(auto it = scores.begin(); it != scores.end(); it++)
        sort(it->second.begin(), it ->second.end());
    
    for(auto q : query) {
        string s[4];
        int score;
        istringstream stt(q);
        stt >> s[0] >> s[1] >> s[1] >> s[2] >> s[2] >> s[3] >> s[3] >> score;
        
        vector<int> v = scores[s[0] + s[1] + s[2] + s[3]];
        
        if(v.size() != 0) {
            auto it = lower_bound(v.begin(), v.end(), score);
            answer.push_back(v.size() - (it - v.begin()));
        }
        else 
            answer.push_back(0);   
    }

    return answer;
}