#include <stdio.h>
#include<iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int num[4];
bool comp1(int a, int b){
	return a < b;
}
bool comp2(int a, int b){
	return a > b;
}
int paixu(int n, int flag){
	int result = 0;

	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n = n / 10;
	}
	if (flag == 0){
		sort(num, num + 4, comp1);
	}
	else if (flag == 1){
		sort(num, num + 4, comp2);
	}
	result = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
	return result;
}

int main(){
	int n, up, down, diff = 0;
	cin >> n;
	up = paixu(n, 1);
	down = paixu(n, 0);
	while (diff != 6174){
		diff = up - down; 
		if (diff == 0){
			printf("%04d - %04d = %04d\n", up, down, diff);
			break;
		}
		printf("%04d - %04d = %04d\n", up, down, diff);
		up = paixu(diff, 1);
		down = paixu(diff, 0);
	}


	//cout << up << ' ' << down;
	return 0;
}
