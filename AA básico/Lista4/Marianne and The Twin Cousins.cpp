
#include <stdio.h>
#include <cstdlib>
#include <vector>

#define MAX 100011

using namespace std;

int main() {
	int n, p1, p2, big, sml;
	vector <bool> p (MAX, true);
	vector <int> tp (MAX, 0);
	
	p[0] = false;
	p[1] = false;
	
	for (int i = 2; i < MAX; i++) {
		if (p[i]) {
			for (int j = i + i; j < MAX; j += i) {
				p[j] = false;
			}
		}
	}
	
	for (int i = 2; i < MAX - 2; i++) {
		if ((p[i] && p[i + 2]) || (p[i] && p[i - 2])) {
			tp[i] = tp[i - 1] + 1;
		} else {
			tp[i] = tp[i - 1];
		}
		//printf("%d:%d  ", i, tp[i]);
	}
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p1, &p2);
		
		big = max(p1, p2);
		sml = min(p1, p2);
		
		printf("%d\n", (tp[big] - tp[sml-1]));
	}
	
	return 0;
}
