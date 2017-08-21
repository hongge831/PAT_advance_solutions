#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin >> str;
	int n, n1, n2;
	/*find the max n1 & n3*/
	n = str.size() + 2;
	n1 = n / 3-1; n2 = n / 3 + n % 3;
	int p=0 ,j = str.size() - 1, spaceN;
	for (int i = 0; i < n1; i++)
	{
		spaceN = n2 - 2;
		printf("%c",str[p++]);
		while (spaceN){
			printf(" ");
			spaceN--;
		}
		printf("%c\n", str[j--]);
	}
	for (int i = p; i <= j; i++)
	{
		cout << str[i];
	}
	return 0;
}