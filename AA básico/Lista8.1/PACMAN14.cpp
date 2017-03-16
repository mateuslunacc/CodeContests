
#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int main () {
	int n, score = 0, max_score = 0;
	char row[MAX];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", row);
		
		for (int j = 0; j < n; j++) {
			int pos = i%2 == 0? j : n - j - 1;
			
			if (row[pos] == 'o') {
				if (++score > max_score) {
					max_score = score;
				}			
			}
			
			if (row[pos] == 'A') {
				score = 0;
			}
		}
	}
	
	printf("%d\n", max_score);
	
	return 0;
}
