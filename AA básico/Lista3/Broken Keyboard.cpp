
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	string sc="";
	int error=0;
	
	while(cin>>s){
		int j=0;
		for(int i=0;i<s.size();i++){
			//cout<<s[i]<<" "<<sc[j]<<endl;
			if(s[i]=='['){
				j=0; error++;
			} else if(s[i]==']') {
				j=i-(error++);
			} else {
				sc.insert(j++,{s[i]});
			}
		}
		cout<<sc<<endl;
		error=0;
		sc="";
	}
	
	
	return 0;
}
