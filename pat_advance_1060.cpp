#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char a[1000], b[1000], c[1000], d[1000];
int findFirstPoint(char a[]){
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == '.'){
			return i;
		}
	}
	return strlen(a);
}
int findFirstNonZero(char a[]){
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] != '.' && a[i] != '0'){
			return i;
		}
	}
	return strlen(a);
}
int main(){
	int n;
	scanf_s("%d %s %s", &n, a, 100, b, 100);
	int potA = 0, potB = 0, numA = 0, numB = 0;
	/*looking for the first point in data*/
	potA = findFirstPoint(a);
	potB = findFirstPoint(b);
	/*looking for the first non-zero number location*/
	numA = findFirstNonZero(a);
	numB = findFirstNonZero(b);
	/*potA also stand for exponent*/
	/*compute the value of exponent*/
	if (potA >= numA){
		potA = potA - numA;
	}
	else{
		potA = potA - numA + 1;
	}
	if (potB >= numB){
		potB = potB - numB;
	}
	else{
		potB = potB - numB + 1;
	}
	if (numA == strlen(a))
		potA = 0;
	if (numB == strlen(b))
		potB = 0;
	/*array c & d is for result*/
	for (int index = 0; index < n; numA++)
	{
		if (a[numA] != '.' && numA < strlen(a)){
			c[index++] = a[numA];
		}
		else if (numA >= strlen(a)){
			c[index++] = '0';
		}
	}
	for (int index = 0; index < n; numB++)
	{
		if (b[numB] != '.' && numB < strlen(b)){
			d[index++] = b[numB];
		}
		else if (numB >= strlen(b)){
			d[index++] = '0';
		}
	}
	if (strcmp(c, d) == 0 && potA == potB){
		printf("YES 0.%s*10^%d", c, potA);
	}
	else{
		printf("NO 0.%s*10^%d 0.%s*10^%d", c, potA, d, potB);
	}

	return 0;
}