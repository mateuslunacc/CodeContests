
#include <stdio.h>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 200002

int main () {
	char a[MAX], b[MAX];
	int sizeA, sizeB, count, sum;
	int a0 = 0; a1 = 0;
	
	scanf("%s %s", a, b);
	sum = 0;
	count = 0;
	sizeA = strlen(a);
	sizeB = strlen(b);
	
	for (int i = 0; i < sizeA; i++) {
		if (a[i] != b[i]) sum++;
		if (a[i]) a1++;
		else a0++;
	}
	
	for (int i = sizeA; i < sizeB; i++) {		
		for (int i = count; i < sizeA; i++) {
		}
		count++;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
