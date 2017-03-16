#include <stdio.h>
#include <thread>

using namespace std;

#define MAX 10001
#define ll long long

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

int pivot(ll a[], int first, int last) {
    ll p = first;
    ll pivotElement = a[first];
 
    for(ll i = first+1 ; i <= last ; i++) {
        if(a[i] <= pivotElement) {
			swap(a[i], a[++p]);
		}
    }
	
	swap(a[p], a[first]);
    
    return p;
}

void quick_sort(ll a[], int first, int last ) {
    ll pivotElement;
 
    if(first < last) {
        pivotElement = pivot(a, first, last);
        
        thread t1(quick_sort, &a, &first, &pivotElement-1);
			
        thread t2([&pivotElement, &last](){ quick_sort(pivotElement + 1, last); });

        t1.join();
        t2.join();
        
        quick_sort(a, first, pivotElement-1);
        quick_sort(a, pivotElement+1, last);
    }
}

int main () {
	ll elements[MAX];
	ll e, size = 0;
	
	while (scanf(" %I64d", &e) != EOF) {
		elements[size++] = e;
	}
	
	quick_sort(elements, 0, size - 1);
	
	for (int i = 0; i < size; i++) {
		printf("%I64d\n", elements[i]);
	}
	
	return 0;
}
