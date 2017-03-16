#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, d, wins=0, streak=0;
	string foes;
	
	cin>>n>>d;
	
	for(int i=0;i<d;i++){
		cin>>foes;
		if(foes.find('0')>110){ //lost
			streak=0;
		} else { //won
			streak++;
		}
		wins=max(wins, streak);
	}
	
	cout<<wins;
	
	return 0;
}
