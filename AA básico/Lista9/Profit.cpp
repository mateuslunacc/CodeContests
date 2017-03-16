#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int n, cost, revenue[MAX];

int max_sub_array (int a[], int cost, int size) {
	int max_profit = 0, best_profit = 0, days = 0;
	
	for (int i = 0; i < size; i++) {
		//best_profit = max(0, best_profit + a[i]);
		//max_profit = max(best_profit, best_profit);
		
		if ((best_profit + a[i])-(cost*(days + 1)) > 0) {
			best_profit = (best_profit + a[i])-(cost*(days + 1));
			printf("best: %d\n", best_profit);
		} else {
			best_profit = 0;
		}
		
		if (max_profit < best_profit) {
			max_profit = best_profit;
			days++;
			printf("max: %d  days: %d\n", max_profit, days);
		}
	}
	
	return max_profit;
}

int main () {
	scanf("%d%d", &n, &cost);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &revenue[i]);
	}
	
	printf("%d\n", max_sub_array(revenue, cost, n));
	
	return 0;
}
