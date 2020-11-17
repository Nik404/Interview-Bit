#include <iostream>
#include <climits>
using namespace std;
struct point{

    int x,y;

};
struct hole{

    int x1,y1,x2,y2,time;

};
int ans;
bool visited[100];
int distance(point src,point dest){
    return abs(src.x-dest.x) + abs(src.y-dest.y);
}
void spaceship(point src,point dest,hole a[],int time,int n){
        
    int tempans = time + distance(src,dest);
    ans = min(ans,tempans);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            point temp1,temp2;
            int value;
            temp1.x = a[i].x1;temp1.y = a[i].y1;
            temp2.x = a[i].x2,temp2.y = a[i].y2;
            
            value = distance(src,temp1);
            spaceship(temp2,dest,a,value+time+a[i].time,n);
            
            value = distance(src,temp2);
            spaceship(temp1,dest,a,value+time+a[i].time,n);
            
            
            visited[i] = false;
        }
    }
    
    
    
    
}
int main() {
    point src,dest;
    cin>>src.x>>src.y>>dest.x>>dest.y;
    int warmholes;
    cin>>warmholes;
    
    hole a[warmholes];
    ans = INT_MAX;
    for(int i=0;i<warmholes;i++){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].time;
    }
    for(int i=0;i<100;i++){
        visited[i] = false;
    }
    spaceship(src,dest,a,0,warmholes);
    cout<<ans;
	return 0;
}
