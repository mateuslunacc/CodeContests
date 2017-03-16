
#include <bits/stdc++.h>

using namespace std;
 
#define MAX 100001

int main () {
    int value,min,cnt;
    int n[10];
    
    scanf("%d",&value);
    min = MAX;
    
    for(int i=1; i<=9; i++) {
        scanf("%d",&n[i]);
        if(min > n[i]) min = n[i];
    }
    
    if(value < min) {
        printf("-1\n");
        return 0;
    }
    
    cnt = value / min;
    for(int i=cnt-1; i>=0; i--) {
        for(int j=9; j>=1; j--) {
            if(value >= n[j] && (value - n[j]) / min >= i) {
                printf("%d",j);
                value -= n[j];
                break;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
