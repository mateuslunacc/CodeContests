#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

vector <bool> primes (int n) {
	vector <bool> p (n, true);	
	p[0] = false;
	p[1] = false;
	
	for (int i = 2; i < n; i++) {
		if (p[i]) {
			for (int j = i + i; j < n; j += i) {
				p[j] = false;
			}
		}
	}
	
	return p;
}

int main(){
	int n, ans_size;
	vector <bool> num_primes;
	vector <int> ans;
	
	scanf("%d",&n);
	num_primes = primes(++n);
	
	for (int i = 2; i < n; i++){
		if (num_primes[i]) {
			ans.push_back(i);
			
			for (int j = 2; round(pow(i, j)) < n; j++){
				int m = round(pow(i, j));
				
				if (!num_primes[m]) {
					ans.push_back(m);
				}
			}
		}
	}
	
	ans_size = ans.size();
	
	printf("%d\n", ans_size);
	for (int i = 0; i < ans_size; i++){
		if (i < ans_size-1) printf("%d ", ans[i]);
		else printf("%d\n", ans[i]);
	}
	
	return 0;
}
