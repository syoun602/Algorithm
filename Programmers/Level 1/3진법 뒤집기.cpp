#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int rem;
    string num = "";
    
    while(n != 0) {
        rem = n % 3;
        n = n / 3;
        num = to_string(rem) + num;
    }
    
    for(int i = 0; i < num.size(); i++)
        answer += (num[i] - '0') * pow(3, i);
    
    return answer;
}