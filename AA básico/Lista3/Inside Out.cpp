#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string s;
	string sc;
	
	cin>>n;
	cin.ignore();
	while(n--){
		getline(cin,s);
		sc="";

		for(int c=(s.size()/2)-1;c>=0;c--){
			sc.push_back(s[c]);
		}
		for(int c=(s.size()-1);c>=s.size()/2;c--){
			sc.push_back(s[c]);
		}
		cout<<sc<<endl;
	}
	
	
	return 0;
}
