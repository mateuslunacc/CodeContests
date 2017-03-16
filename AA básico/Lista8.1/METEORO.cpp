#include <bits/stdc++.h>

using namespace std;

int main () {
	int x1, y1, x2, y2, n, x, y, test = 0, count;
	
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	while (x1 || x1 || y1 || y2) {
		count = 0;
		
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			
			if (x1 <= x && x2 >= x && y2 <= y && y1 >= y) {
				count++;
			}
		}
		
		printf("Teste %d\n%d\n\n", ++test, count);
		
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	}
	
	return 0;
}
