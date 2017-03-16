
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;



int binary_search(vector <int> v, int begin, int end, int e) {
	int half;
	
	while (begin <= end) {
		half = begin + (end - begin)/2;
		
		if (v[half] == e) {
			while (half > -1 && v[half] == e) half--;
			return ++half;
		}
		else if (v[half] < e) begin = ++half;
		else end = --half;
	}
	
	return -1;
}

int main() {
	int n, q, c = 1;
	vector <int> m;
	
	scanf("%d %d", &n, &q);
	
	while(n && q) {
		for (int i = 0; i < n; i++) {
			int input;
			scanf("%d", &input);
			m.push_back(input);
		}
		sort(m.begin(), m.end());

		printf("CASE# %d:\n", c++);
		for (int i = 0; i < q; i++) {
			int input;
			scanf("%d", &input);
			
			int p = binary_search(m, 0, n - 1, input);
			
			if (p == -1) {
				printf("%d not found\n", input);
			} else {
				printf("%d found at %d\n", input, ++p);				
			}
		}
		
		scanf("%d %d", &n, &q);
		m.clear();
	}
	
	
}
