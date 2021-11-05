#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count(int n) {
    
    int cnt = 0;
    
    while(n > 0) {
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    
    int check = count(n);
    while(1) {
        n++;
        if(count(n) == check) break;
    }
    
    return n;
}