#include <stdio.h>
#include <iostream>
using namespace std;
bool isprime(int n){
	if (n < 2)return false;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)return false;
	}return true;
}
int main(){
	int n, m;
	cin >> n;
	int rvs = 0;
	while (n > 0){
		cin >> m;
		int num = n;
		while (n){
			rvs = rvs*m + (n % m);
			n /= m;
		}
		if (isprime(num) && isprime(rvs)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		cin >> n;
		rvs = 0;
	}
	return 0;
}