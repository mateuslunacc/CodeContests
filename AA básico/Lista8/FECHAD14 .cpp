#include <stdio.h>

using namespace std;

int main () {
	int n, m, moves = 0, pins[1001];
	
	scanf("%d%d", &n, &m);
	
	for(int p = 0; p < n; p++) {
		scanf("%d", &pins[p]);
	}
	
	for(int p = 0; p < n - 1; p++) {
		int diff = m - pins[p];
		pins[p] += diff;
		pins[p+1] += diff;
		moves += diff > 0? diff : -diff;
	}

	int diff = m - pins[n-1];
	moves += diff > 0? diff : -diff;	

	printf("%d\n", moves);
	
	return 0;
}
