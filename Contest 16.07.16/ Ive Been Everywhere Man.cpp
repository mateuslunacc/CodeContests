#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int t, n;
	string city;
	unordered_set <string> cities;
	
	cin>>t;

	for (int c = 0; c < t; c++) {
		cin>>n;
		
		for (int i = 0; i < n; i++){
			cin>>city;
			
			cities.insert(city);
		}
		
		cout<<cities.size()<<endl;
		
		cities.clear();
	}
	return 0;
}
