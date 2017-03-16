#include <iostream>
#include <algorithm>

using namespace std;

const int oneToNine[9] = {1, 2, 3, 4, 5, 6, 7 ,8, 9};

bool checkRows(int s[][9]){
	bool correct = true;
	int sc[9];
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			sc[j]=s[i][j];
		}
		sort(sc,sc+9);
		if(!equal(sc,sc+9,oneToNine)){
			correct = false;
		}
	}
	return correct;
}

bool checkColumns(int s[][9]){
	bool correct = true;
	int sc[9];
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			sc[j]=s[j][i];
		}
		sort(sc,sc+9);
		if(!equal(sc,sc+9,oneToNine)){
			correct = false;
		}
	}
	return correct;
}

bool checkBlocks(int s[][9]){
	bool correct = true;
	int sc[9];
	int index;
	
	for(int m=0;m<9;m+=3){
		for(int n=0;n<9;n+=3){
			index=0;
			for(int i=m;i<m+3;i++){
				for(int j=n;j<n+3;j++){
					sc[index]=s[i][j];
					index++;
				}
			}
			sort(sc,sc+9);
			if(!equal(sc,sc+9,oneToNine)){
				correct = false;
			}
		}
	}
	return correct;
}

int main(){
	int n;
	int s[9][9];
	
	cin>>n;
	for(int g=1;g<=n;g++){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>s[i][j];
			}
		}
		if(checkColumns(s) && checkRows(s) && checkBlocks(s)) {
			cout<<"Instancia "<<g<<"\nSIM\n\n";
		} else {
			cout<<"Instancia "<<g<<"\nNAO\n\n";
		}
	}
	
	return 0;
	
}
