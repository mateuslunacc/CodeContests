
#include <iostream>
#include <string>

using namespace std;

int numToOne(string s) {
	int n=0;
	do {
		n = 0;
		for(int i=0;i<s.size();i++){
			n+=s[i]-48;
		}
		s = to_string(n);
	} while(s.size()>1);
	
	return n;
}

int main(){
	string n, m;
	int no=1, mo=1;
	
	cin>>n>>m;
	do {
		no=numToOne(n);
		mo=numToOne(m);
		if(!(no||mo)) break;
		
		if(no==mo){
			cout<<0<<endl;
		} else if(no>mo){
			cout<<1<<endl;
		} else {
			cout<<2<<endl;
		}
		cin>>n>>m;
	} while(1);
	return 0;
}
