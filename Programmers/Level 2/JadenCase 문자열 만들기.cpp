#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool upper = true; 
    
    for(int i = 0 ; i < s.size(); i++) {
        if(upper) 
            s[i] = toupper(s[i]);
        else 
            s[i] = tolower(s[i]);
        
        upper = false;
        
        if(s[i] == ' ')
            upper = true;        
    }
    
    return s;
}