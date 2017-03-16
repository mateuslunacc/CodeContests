
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
	int k, m, n, v=0, count=0;
	char l1, l2;
	char fav_letters[30], name[100001];
	unordered_map<char, char> letters, best_letters;
	int letters_count[30];
	bool fav[30];

    scanf("%d %d %d", &k, &m, &n);
    scanf("\n%s", fav_letters);
    scanf("\n%s", name);
	
	for(int i=0;i<26;i++){
		letters_count[i]=0;
		fav[i]=false;
	}
	for(int i=0;i<k;i++){
		fav[fav_letters[i]-'a']=true;
	}
	for(int i=0;i<m;i++){
		int p = name[i]-'a';
		letters_count[p]++;
		if(fav[p]) count++;
		letters.insert(pair<char, char>(name[i],name[i]));
	}
	v=count;
	best_letters=letters;
	
	for(int i=0;i<n;i++){
		scanf("\n%c %c", &l1, &l2);

		int n1=l1-'a';
		int n2=l2-'a';
		
		if(fav[n1] && !fav[n2]) 
			count+=(letters_count[n2]-letters_count[n1]);
		if(fav[n2] && !fav[n1]) 
			count+=(letters_count[n1]-letters_count[n2]);
		
		int aux = letters_count[n1];	//swap letters count
		letters_count[n1]=letters_count[n2];
		letters_count[n2]=aux;

		for(auto it=letters.begin();it!=letters.end();++it){
			if(it->second==l1) it->second=l2;
			else if(it->second==l2) it->second=l1;
		}

		if(count>v) {
			v=count;
			best_letters=letters;
		}
		
	}

	for(int i=0;i<m;i++){
		name[i]=best_letters[name[i]];
	}
	
	printf("%d\n%s\n",v,name);
	
	return 0;
}
