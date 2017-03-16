#include <iostream>
using namespace std;

int main() {
	int a, b, m, n;

	cin>>a>>b;

	if(a>b) {
		m=a;
		n=b;
	} else {
		m=b;
		n=a;
	}
	
	if (m%n==0) cout<<"Sao Multiplos\n";
	else cout<<"Nao sao Multiplos\n";

	return 0;
}
