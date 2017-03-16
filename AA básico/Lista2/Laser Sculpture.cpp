
#include <iostream>

using namespace std;

int main(){
	int a, c;
	int b[10010];
	int steps;
	
	cin>>a>>c;
	
	while(a||c){
		int last = a;
		steps = 0;
		
		for(int i=0;i<c;i++){
			cin>>b[i];
			if(last>b[i]) {
				steps+=last-b[i];
			}
			last=b[i];
		}

		cout<<steps<<endl;
		
		cin>>a>>c;
	}
	
	return 0;
}
