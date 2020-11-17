#include <iostream>
#include <unordered_map>
#include<queue>
#include <vector>
using namespace std;

int gasStation(int *gas,int *cost,int n){
    int sum = 0;
    int start = 0;
    int tank = 0;
    for(int i = 0;i<n;i++){
        sum += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if(tank < 0){
            start = i + 1;
            tank = 0;
        }
    }
    if(sum < 0) return -1;
    return start;
}
int main() {
    int n;
    cin>>n;
    int gas[n],cost[n];
    for(int i=0;i<n;i++){
        cin>>gas[i];
    }
     for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<gasStation(gas,cost,n);
	return 0;
}


// input

// 5
// 1 2 3 4 5
// 3 4 5 1 2