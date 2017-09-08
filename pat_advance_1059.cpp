#include <stdio.h>
#include <iostream>
#include <math.h>
#define M 100000//M is just a scale,can try several times
using namespace std;
int prime[M];
int main(){
	/*prime table initialize*/
	/*0 is prime i is not prime*/
	for (int i = 2; i*i < M; i++)
	{
		for (int j = 2; i*j < M; j++)
		{
			prime[i*j] = 1;
		}
	}
	/*table initial end*/
	long int num;
	bool flag = false;
	scanf_s("%ld", &num);
	printf("%d=", num);
	if (num == 1)printf("1");
	for (int i = 2; num > 2; i++)
	{
		int cnt = 0, f = 0;
		while (prime[i] == 0 && num % i == 0){
			cnt++;
			num /= i;
			f = 1;
		}
		/*f means there is at least one prime component*/
		if (f){
			/*flag means there are more than 2 components*/
			if (flag){
				printf("*");
			}
			printf("%d", i);
			flag = true;
		}
		if (cnt >= 2){
			printf("^%d", cnt);
		}

	}


	return 0;
}