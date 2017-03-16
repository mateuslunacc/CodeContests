
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	string m, k;
	map <string, int> murderers;
	while(cin>>m>>k){
		if(murderers.find(k)!=murderers.end()){ 
			murderers.at(k)=0;
		} else {
			murderers.insert(pair<string,int>(k,0));
		}
		if(murderers.find(m)!=murderers.end()){
			if(murderers.at(m)) {
				murderers.at(m)++;
			}
		} else {
			murderers.insert(pair<string,int>(m,1));
		}
	}
	
	cout<<"HALL OF MURDERERS\n";
	for(map<string,int>::iterator it=murderers.begin();it!=murderers.end();++it){
		if(it->second){
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
	
	return 0;
}
