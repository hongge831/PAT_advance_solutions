#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int asc[260] = { 0 };
int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i < str2.length(); i++)
	{
		asc[str2[i]]++;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		if (asc[str1[i]] == 0)
			printf("%c", str1[i]);
	}
	return 0;
}