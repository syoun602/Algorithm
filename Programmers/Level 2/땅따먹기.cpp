#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = land.size()-1;
    int prev = -1;
    
    for(int i = 0; i < answer; i++) {
        land[i+1][0] += max({land[i][1], land[i][2], land[i][3]});
        land[i+1][1] += max({land[i][0], land[i][2], land[i][3]});
        land[i+1][2] += max({land[i][0], land[i][1], land[i][3]});
        land[i+1][3] += max({land[i][0], land[i][1], land[i][2]});
    }

    return max(max(land[answer][0], land[answer][1]), max(land[answer][2], land[answer][3]));
}