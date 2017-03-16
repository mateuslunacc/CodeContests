
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	int q, e;
	int Q[2002], E[2002];
	
	cin>>q>>e;
	
	for(int i=0;i<e;i++){
		cin>>E[i];
	}
	for(int i=0;i<q;i++){
		cin>>Q[i];
		if(find(begin(E), begin(E)+e, Q[i]) != begin(E)+e) { //visited
			cout<<"0\n";
		} else {
			cout<<"1\n";
			E[e++]=Q[i];
		}
	}
	return 0;
}
