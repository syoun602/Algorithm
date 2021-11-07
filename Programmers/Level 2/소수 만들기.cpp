#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

int answer = 0;

bool prime(int num) {
    
    if(num == 1 || num == 2)
        return true;
    
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

void dfs(int total, int cnt, int idx, vector<int> &nums) {
    
    if(cnt == 3) {
        if(prime(total))
            answer++;
        return;
    }
    
    for(int i = idx; i < nums.size(); i++) {
        total += nums[i];
        dfs(total, cnt + 1, i + 1, nums);
        total -= nums[i];
    }
    
}

int solution(vector<int> nums) {    
    dfs(0, 0, 0, nums);
    
    return answer;
}