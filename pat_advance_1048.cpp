#include <stdio.h>
#include <iostream>
using namespace std;
int hashTable[1005] = { 0 };
int main(){
	int n, m, tempIn;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &tempIn);
		hashTable[tempIn]++;
	}
	for (int i = 0; i <= m/2; i++)
	{
		if (hashTable[i]-- != 0 && hashTable[m - i]-- != 0){
			printf("%d %d", i,m-i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}