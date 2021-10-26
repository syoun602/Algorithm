#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int arr[10] = {};

    for(auto n : numbers)
        arr[n] = n;
    
    for(int i = 0; i <= 9; i++)
        if(arr[i] == 0) answer += i;
    
    return answer;
}