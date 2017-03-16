
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	string e;
	bool correct;
	while(cin>>e){
		stack <char> p;
		correct = true;
		
		for(int i=0;i<e.size() && correct;i++){
			switch (e[i]){
				case '(':
				p.push('(');
				break;
				case ')':
				if(p.empty()) {
					correct=false; break;
				} else {
					p.pop();
				}
			}
		}
		if(correct && p.empty()) cout<<"correct"<<endl;
		else cout<<"incorrect"<<endl;
		
	}
}
