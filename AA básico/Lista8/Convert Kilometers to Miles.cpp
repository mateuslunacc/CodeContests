
#include <stdio.h>

using namespace std;

//int 10^4, ll 10^18
#define MAX 22
#define ll long long
#define vi vector <int>
#define vll vector <ll>
#define pb push_back

int f[MAX];

void fib(ll len) {
	f[0] = 1;
	f[1] = 2;
	
	for (int i = 2; i < len; i++) {
		f[i] = f[i-1] + f[i-2];
	}
}

int main () {
	int t, d;
	
	fib(MAX+1);
	
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		int sum = 0;
		scanf("%d", &d);
		
		for (int i = MAX; i > 0; i--) {
			if (d - f[i] >= 0) {
				//printf("%d\n", f[i-1]);
				sum += f[i-1];
				d -= f[i];
			}
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}
