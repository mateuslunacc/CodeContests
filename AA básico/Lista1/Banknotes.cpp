#include <iostream>

using namespace std;

int main() {
	long n;
	int bankNotes[] = {100, 50, 20, 10, 5, 2, 1};
	
	cin>>n;
	cout<<n<<"\n";
	for(int i=0;i<7;i++){
		cout<<n/bankNotes[i]<<" nota(s) de R$ "<<bankNotes[i]<<",00\n";
		n%=bankNotes[i];
	}
	
	return 0;
}
