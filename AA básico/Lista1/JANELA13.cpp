#include <iostream>
#include <cstring>

using namespace std;

int NUM_WINDOWS = 3;
int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 100;
int WINDOW_LEAF = 200;

int main(){
	int f[NUM_WINDOWS];
	int w[WINDOW_WIDTH];
	int cnt = 0;
	
	memset(w, 0, sizeof(w));

	for(int i=0;i<NUM_WINDOWS;i++){
		cin>>f[i];
		for(int j=f[i];j<f[i]+WINDOW_LEAF;j++){
			if(!w[j]){
				cnt++;
				w[j]=1;
			}
		}
	}
	
	cout<<(WINDOW_WIDTH-cnt)*WINDOW_HEIGHT<<"\n";
	
	return 0;
}
