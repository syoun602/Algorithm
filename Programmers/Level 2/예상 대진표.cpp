#include <iostream>
#include <cmath> 

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    for(int i = 1; pow(2, i) <= n; i++) {
        if((a % 2 == 1 && a + 1 == b)  || b % 2 == 1 && b + 1 == a)
            break;
        answer++;
        
        if(a % 2 == 1)
            a++;
        if(b % 2 == 1)
            b++;
        
        a /= 2, b /= 2;
        
    }

    return answer;
}