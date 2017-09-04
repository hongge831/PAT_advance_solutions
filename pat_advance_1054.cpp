#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
map<int, int> mp;
int main(){
	int n, m;
	cin >> n >> m;
	int data;
	for (int i = 0; i < n*m; i++)
	{
		scanf_s("%d",&data);
		mp[data]++;
		if (mp[data] > 0.5*m*n){
			printf("%d",data);
			break;
		}
	}
	return 0;
}