#include <string>
#include <vector>
#include <iostream>

using namespace std;

string mkstr(long long n) {
    int cnt = 0;
    string str = "";
    while(n != 0) {
        if(n % 2 == 1)
            str = '1' + str;
        else
            str = '0' + str;
        n /= 2;
    }
    
    return str;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size(); i++) {
        if(!(numbers[i] % 2))
            answer.push_back(numbers[i] + 1);
        else {
            long long bit = 1;
            
            while(numbers[i] & bit)
                bit = bit << 1;
            
            bit /= 2;
            answer.push_back(numbers[i] + bit);
        }
    }
    
    return answer;
}