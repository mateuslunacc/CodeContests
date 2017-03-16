#include <iostream>

using namespace std;

int main(){
	int n, wall[9][9];
	
	cin>>n;
	while(n--){
		//get input
		for(int i=0;i<9;i++){
			for(int j=0;j<=i;j++){
				if(i%2==0 && j%2==0){
					cin>>wall[i][j];
				}
			}
		}
		//set odd rows
		for(int i=2;i<9;i+=2){
			for(int j=1;j<i;j+=2){
				wall[i][j]=(wall[i-2][j-1]-wall[i][j-1]-wall[i][j+1])/2;
			}
		}
		//set even rows
		for(int i=1;i<8;i+=2){
			for(int j=0;j<i+1;j++){
				wall[i][j]=wall[i+1][j]+wall[i+1][j+1];
			}
		}
		//output
		for(int i=0;i<9;i++){
			for(int j=0;j<=i;j++){
				if(i!=j) cout<<wall[i][j]<<" ";
				else cout<<wall[i][j]<<endl;
			}
		}
	}
}
