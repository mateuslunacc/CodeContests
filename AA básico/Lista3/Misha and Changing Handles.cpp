
#include <iostream>
#include <unordered_set>
#include <string>
#include <map>

using namespace std;

string findName(map<string,string> m, string s){
	string name="";
	
	for(map<string,string>::iterator it=m.begin();it!=m.end();++it){
		if(it->second==s){
			name=it->first;
			break;
		}
	}
	return name;
}

int main(){
	int n;
	map <string, string> handles;
	unordered_set <string> handlesUsed;
	string oldHandle, newHandle;
	
	cin>>n;
	while(n--){
		cin>>oldHandle>>newHandle;
		
		if(handlesUsed.find(newHandle) == handlesUsed.end()) { //new isnt used
			handlesUsed.insert(oldHandle);
			handlesUsed.insert(newHandle);
			string usingHandle=findName(handles, oldHandle);
			if(usingHandle==""){ //old isnt in handles
				handles.insert(pair<string,string>(oldHandle,newHandle));
			} else {
				handles[usingHandle]=newHandle;
			}
		}
	}
	
	cout<<handles.size()<<endl;
	for(map<string,string>::iterator it=handles.begin();it!=handles.end();++it){
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	return 0;
}

