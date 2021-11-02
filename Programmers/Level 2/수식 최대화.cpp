#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long calculate(char &op, long long &num1, long long &num2) {
    if(op == '+')
        return num1 + num2;
    else if(op == '-')
        return num1 - num2;
    else
        return num1 * num2;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> op;
    string temp = "";
    
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            nums.push_back(stoi(temp));
            op.push_back(expression[i]);
            temp = "";
            continue;
        }
        temp += expression[i];
        
        if(i == expression.size() - 1)
            nums.push_back(stoi(temp));              
    }
    
    long long win;
    string seq = "*+-";
    
    do {
        vector<long long> n_temp = nums;
        vector<char> o_temp = op;
        
        for(int i = 0; i < seq.size(); i++) {
            for(int j = 0; j < o_temp.size(); j++) {
                if(seq[i] == o_temp[j]) {
                    n_temp[j] = calculate(seq[i], n_temp[j], n_temp[j+1]);
                    n_temp.erase(n_temp.begin() + j + 1);
                    o_temp.erase(o_temp.begin() + j);
                    j--;
                }
            }
        }
        win = abs(n_temp[0]);
        answer = max(answer, win);
        
    } while(next_permutation(seq.begin(), seq.end()));
    
    return answer;
}