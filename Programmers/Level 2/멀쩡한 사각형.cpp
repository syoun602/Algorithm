#include <iostream>

using namespace std;

long long GCD(int a, int b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a%b);
}
long long solution(int w,int h) {
    long long answer = 1;
    
    int gcd = GCD(w, h);
    
    answer = (long long) w * h - (w+h) + gcd;
    
    return answer;
}