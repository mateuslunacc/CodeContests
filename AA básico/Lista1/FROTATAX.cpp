#include <iostream>

using namespace std;

int main(){
	float a, g, ra, rg;
	
	cin>>a>>g>>ra>>rg;
	
	if(rg/g >= ra/a) cout<<"G\n";
	else cout<<"A\n";
	
	return 0;
}
