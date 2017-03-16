
#include <iostream>


using namespace std;

#define ll long long

string fromDecimal(ll n, int b) {
   string chars = "0123456789ABCDEFGHIJ";
   string result = "";
      
   while(n>0) {
      result = chars.charAt(n%b) + result;
      n/=b;
   }
      
   return result;
}

int toDecimal(int n, int b) {
   int result = 0;
   int multiplier = 1;
      
   while(n>0) {
      result += n%10*multiplier;
      multiplier *= b;
      n /= 10;
   }
      
   return result;
}

int main () {
	
	
	return 0;
}
