#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int begin[55], end[55], order[55];
	for (int i = 1; i < 55; i++)
	{
		cin >> order[i];
		end[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 55; j++)
		{
			begin[j] = end[j];
		}
		for (int k = 1; k < 55; k++)
		{
			end[order[k]] = begin[k];
		}
	}
	char c[5] = {'S','H','C','D','J'};
	for (int i = 1; i < 55; i++)
	{
		printf("%c%d",c[(end[i]-1)/13],(end[i]-1)%13+1);
		if (i != 54)
			printf(" ");
	}
	return 0;
}