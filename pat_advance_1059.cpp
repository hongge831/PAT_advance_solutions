#include <stdio.h>
#include <iostream>
#include <math.h>
#define M 100000
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
		if (f){
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