#include <iostream>

using namespace std;

int main() {
	int n, ticket, winner;
	int test=0;
	
	cin>>n;
	while(n){
		for(int i=1;i<=n;i++){
			cin>>ticket;
			if(i==ticket) winner=i;
		}
		test++;
		cout<<"Teste "<<test<<"\n"<<winner<<"\n\n";
		cin>>n;
	}
	
	return 0;
}
