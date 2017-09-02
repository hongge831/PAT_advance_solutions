#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int right = 0, left = 0, cur, a = 1, ans = 0;
	while (n / a){
		left = n / (a * 10);
		right = n%a;
		cur = n / a % 10;
		if (cur == 0){
			ans += left*a;
		}
		else if (cur == 1){
			ans += left*a + right + 1;
		}
		else{
			ans += (left + 1)*a;
		}
		a *= 10;
	}
	cout << ans;
	return 0;
}