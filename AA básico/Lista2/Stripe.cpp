
#include <iostream>

using namespace std;

int main(){
	int n, ans=0;
	int s[100001], sp[100001], sn[100001];

	cin>>n;

	sp[0]=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		sp[i+1]=s[i]+sp[i];
	}
	
	sn[n]=0;
	for(int i=n-1;i>0;i--){
		sn[i]=s[i]+sn[i+1];
		if(sn[i]==sp[i]) ans++;
	}
	cout<<ans;
	return 0;
}
