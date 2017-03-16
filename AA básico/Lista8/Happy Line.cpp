#include <bits/stdc++.h>

using namespace std;

#define MAX 200002

int main (){
	int n; 
	int line[MAX], base[MAX], payback[MAX];
	bool possible = true;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &line[i]);
		base[i] = n-i-1;
		payback[i] = line[i] - base[i];
	}
	
	sort(payback, payback+n);
	
	for (int i = 0; i < n; i++) {		
		line[i] = payback[i] + base[i];
		if (i && line[i] < line[i-1]) {
			possible = false;
		}
	}
	
	if (possible) {
		for (int i = 0; i < n; i++) {
			printf("%d ", line[i]);
		}
	} else {
		printf(":(");
	}
	printf("\n");

	return 0;
}
