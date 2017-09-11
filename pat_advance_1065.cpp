#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	long long int t, a, b, c, sum;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		scanf_s("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0){
			printf("Case #%d: true\n", i + 1);
		}
		/*sum>=0 is errorable place!!!!*/
		else if (a < 0 && b < 0 && sum>=0){
			printf("Case #%d: false\n", i + 1);
		}
		else{
			if (sum > c){
				printf("Case #%d: true\n", i + 1);
			}
			else{
				printf("Case #%d: false\n", i + 1);

			}
		}
	}
	return 0;
}