#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int n, type, e, res[3]={0,0,0};
	queue<int> q;
	priority_queue<int> p;
	stack<int> s;
	
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>type>>e;
			
			if(type==1){
				q.push(e); p.push(e); s.push(e);
			} else {
				int out_q = q.front(); q.pop();
				int out_p = p.top(); p.pop();
				int out_s = s.top(); s.pop();
				//cout<<"q: "<<out_q<<" p: "<<out_p<<" s: "<<out_s<<endl;
				if(out_q == e && res[0]>=0) res[0]=1;
				else res[0]=-1;
				
				if(out_p == e && res[1]>=0) res[1]=1;
				else res[1]=-1;
				
				if(out_s == e && res[2]>=0) res[2]=1;
				else res[2]=-1;
			}
		}
		//cout<<"res: "<<"q: "<<res[0]<<" p: "<<res[1]<<" s: "<<res[2]<<endl;
		if(res[0]==-1 && res[1]==-1 && res[2]==-1){
			cout<<"impossible"<<endl;
		} else if((res[0]==1 && res[1]==1) || (res[0]==1 && res[2]==1) || (res[2]==1 && res[1]==1)) {
			cout<<"not sure"<<endl;
		} else if(res[0]==1){
			cout<<"queue"<<endl;
		} else if(res[1]==1) {
			cout<<"priority queue"<<endl;
		} else if(res[2]==1) {
			cout<<"stack"<<endl;
		}
		
		res[0]=0;res[1]=0;res[2]=0;
		while(!q.empty()) q.pop();
		while(!p.empty()) p.pop();
		while(!s.empty()) s.pop();
	}
	
	return 0;
}
