#include <iostream>

using namespace std;

long convert(string num) {
	int n = 0, size = num.size();

	for (int i = 0; i < size; i++) {
		n += (num[size-i-1]-48)*(1<<i);
	}

	return n;
}

int main() {
	long pairs, n1, n2;
	bool mmc = false;
	string s1, s2;
	
	cin>>pairs;
	
	for (long i = 0; i < pairs; i++) {
		cin>>s1>>s2;
		
		n1 = convert(s1);
		n2 = convert(s2);
				
		long d = 2;
		while (d*d <= n1 && d*d <= n2) {
			if (n1 % d == 0 && n2 % d == 0) {
				mmc = true;
				break;
			}
			d++;
		}
		
		if (mmc) {
			cout<<"Pair #"<<i+1<<": All you need is love!"<<endl;
		} else {
			cout<<"Pair #"<<i+1<<": Love is not all you need!"<<endl;			
		}
		mmc = false;
	}
	
	return 0;
}
