#include <iostream>

using namespace std;

int main(){
	int k, n, w, sum=0;
	
	cin>>k>>n>>w;
	
	for(int i=1;i<=w;i++){
		sum+=k*i;
	}
	sum = max(0, sum-n);
	cout<<sum<<endl;
	return 0;
}
