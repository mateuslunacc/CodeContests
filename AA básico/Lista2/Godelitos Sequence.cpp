#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
	int n;
	while(scanf("%d", &n) != EOF) {
		string s[44];
		s[0] = "3";
 
		for(int i=1;i<n;i++){
			string num;
			for(int j=0;j<s[i-1].size();j++){
				num=s[i-1][j];
				int count = 1;
				while(j+1 < s[i-1].size() && s[i-1][j] == s[i-1][j+1]) {
					count++;
					j++;
				}
				s[i]+=to_string(count);
				s[i]+=num;
			}
		}
		cout<<s[--n]<<endl;
	}
	return 0;
}
