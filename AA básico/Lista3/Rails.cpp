
#include <stdio.h>
#include <stack>

using namespace std;

int main(){
	int n, coach[1001], exit;
	stack <int> station;

	scanf("%d",&n);

	while(true){
		scanf("%d",&coach[n-1]);
		if(!coach[n-1]) {
			printf("\n");
			scanf("%d",&n);
			if (!n) break;
			else scanf("%d",&coach[n-1]);
		}
		
		for(int i=n-2;i>=0;i--) scanf("%d",&coach[i]);
		
		exit=n;
		for(int i=0;i<n;i++){
			if(coach[i]==exit){
				exit--;
				while(!station.empty() && station.top()==exit) {
					exit--;
					station.pop();
				}
				
			} else {
				station.push(coach[i]);
			}
		}

		while(!station.empty() && station.top()==exit) {
			exit--;
			station.pop();
		}
		
		if(station.empty()) {
			printf("Yes\n");
		} else {
			printf("No\n");
			do {
				station.pop();
			} while(!station.empty());
		}
		
	}
	
	return 0;
}
