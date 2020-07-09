#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int TOH(char s,char d,char t, int n){
	if(n>=1){
		
		TOH(s,t,d,n-1);
		cout << "move disc " << n << " from " << s << " to " << d << endl;
		TOH(t,d,s,n-1);
	}
	
	return (pow(2,n)-1);
}

int main(){
	char a {'s'}, b {'d'}, c {'t'};
	int n {0};
	cin >> n;

	cout << TOH(a, b, c, n) << endl;
	return 0;
}