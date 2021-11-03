#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int total = 0;
    queue<int> trucks;
    queue<int> bridge;
    
    for(int i = 0; i < truck_weights.size(); i++)
        trucks.push(truck_weights[i]);
    
    for(int i = 0; i < bridge_length; i++)
        bridge.push(0);
    
    while(!trucks.empty() || !bridge.empty()) {
        
        answer++;
        total -= bridge.front();
        bridge.pop();
        
        if(!trucks.empty()) {
            if(total + trucks.front() <= weight) {
                bridge.push(trucks.front());
                total += trucks.front();
                trucks.pop();
            }
            else
                bridge.push(0);
        }
    }
    
    return answer;
}