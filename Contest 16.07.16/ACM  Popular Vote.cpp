#include <stdio.h>
#include <utility>

using namespace std;

int main() {
	int t, n, c, votes=0;
	pair <int, int> winner (0, 0);
	bool tie = false;
	
	scanf("%d",&t);
	
	for (int i = 0; i < t; i++) {
		scanf("%d",&n);
		
		for (int j = 0; j < n; j++) {
			scanf("%d", &c);
			votes += c;
			if(c > winner.second) {
				winner.first = j+1;
				winner.second = c;
				tie = false;		
			} else if (c == winner.second) {
				tie = true;
			}
		}
		
		if (tie) {
			printf("no winner\n");			
		} else {
			if (winner.second > votes/2) {
				printf("majority winner %d\n", winner.first);
			} else {
				printf("minority winner %d\n", winner.first);
			}
		}
		
		tie = false;
		winner.first = 0;
		winner.second = 0;
		votes = 0;
		
	}
	
	
	return 0;
}
