#include <iostream>

using namespace std;

int scoreSum(int b[], int left, int n){
	int sum=-1, sameColor, right=left;
	int lastColor=b[left];
	
	do {
		sameColor=0;
		while(right<n && b[right]==lastColor){
			sameColor++;			
			++right;
		}

		while(left>=0 && b[left]==lastColor){
			++sameColor;
			--left;
		}

		if(right<n && b[right]!=lastColor){
			lastColor=b[right];
		}
		if(left>=0 && b[left]!=lastColor) {
			lastColor=b[left];
		}

		if(sameColor >= 3){
			sum+=sameColor;
		} else {
			sameColor=0;
		}
	} while(sameColor);
	
	return sum;
}

int main(){
	int n, k, x;
	int score=0, balls[101];
	
	cin>>n>>k>>x;
	for(int i=0;i<n;i++) {
		cin>>balls[i];
	}

	for(int i=0;i<n-1;i++){
		if(balls[i]==x){
			score = max(scoreSum(balls, i, n), score);
		}
	}
	
	cout<<score<<endl;
	
	return 0;
}
