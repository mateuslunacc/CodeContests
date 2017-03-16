#include <iostream>

using namespace std;

int main() {
	int m, n;
	
	cin>>m>>n;
	if(min(m,n)%2==0) cout<<"Malvika\n";
	else cout<<"Akshat\n";

	return 0;
}
