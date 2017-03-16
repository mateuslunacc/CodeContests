#include <stdio.h>

using namespace std;

#define MAX 10001
#define ll long long

void swap(ll& a, ll& b) {
    int temp = a;
    a = b;
    b = temp;
}

void max_heapify(ll* a, ll size, ll index) {
	ll right = (index + 1) << 1;
	ll left = right - 1;
	ll largest = 0;

	if (left < size && a[left] > a[index])
		largest = left;
	else
		largest = index;

	if (right < size && a[right] > a[largest])
		largest = right;

	if (largest != index) {
		swap(a[index], a[largest]);
		max_heapify(a, size, largest);
	}
}

void heap_sort(ll* a, ll count) {
	ll size = count;

	for (int p = (size - 1) >> 1; p >= 0; --p)
		max_heapify(a, size, p);

	for (ll i = count - 1; i > 0; --i) {
		swap(a[i], a[0]);
		max_heapify(a, --size, 0);
	}
}

int main () {
	ll elements[MAX];
	ll e, size = 0;
	
	while (scanf(" %I64d", &e) != EOF) {
		elements[size++] = e;
	}
	
	heap_sort(elements, size);
	
	for (int i = 0; i < size; i++) {
		printf("%I64d\n", elements[i]);
	}
	
	return 0;
}

