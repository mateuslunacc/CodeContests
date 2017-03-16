

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, bills[4] = {0, 0, 0, 0};
	int test = 1;
	
	scanf("%d", &n);

	while (n) {
		
		if (n >= 50) {
			bills[0] += n/50;
			n = n % 50;
		}
		if (n >= 10) {
			bills[1] += n/10;
			n = n % 10;
		}
		if (n >= 5) {
			bills[2] += n/5;
			n = n % 5;
		}
		if (n >= 1) {
			bills[3] += n/1;
			n = n % 1;
		}				
		
		printf("Teste %d\n", test++);
		for (int i = 0; i < 4; i++) {
			printf("%d ", bills[i]);
			bills[i] = 0;
		}
		printf("\n\n");
		
		scanf("%d", &n);
		
	}
	
	return 0;
}
