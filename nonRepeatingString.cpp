#include <iostream>
#include <unordered_map>
#include<queue>
using namespace std;

string nonRepeatingString(string s){
    unordered_map<char,int> m;
    queue<char> q;
    string output = "";
    for(auto c:s){
        m[c]++;
        q.push(c);
        while(!q.empty() and m[q.front()] > 1){
            q.pop();
        }
            if(!q.empty()){
                output.push_back(q.front());
            }
            else{
                output.push_back('#');
            }
        
    }
    return output;
}
int main() {
	string a;
	cin>>a;
	cout<<nonRepeatingString(a)<<endl;
	return 0;
}


// input
// abadbc
// abcabc
