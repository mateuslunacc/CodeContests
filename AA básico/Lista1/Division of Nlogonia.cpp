#include <iostream>
#include <string>

using namespace std;

string direction(int n, int m, int x, int y) {
	if(x<n && y<m) return "SO";
	if(x<n && y>m) return "NO";
	if(x>n && y<m) return "SE";
	if(x>n && y>m) return "NE";
	return "divisa";
}

int main () {
	int k;
	int n, m;
	int x, y;
	cin>>k;
	while(k) {
		cin>>n>>m;
		for(;k>0;k--){
			cin>>x>>y;
			cout<<direction(n,m,x,y)<<"\n";
		}
		cin>>k;
	}
	
	return 0;
}
