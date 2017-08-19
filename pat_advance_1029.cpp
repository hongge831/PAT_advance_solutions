#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long int>v1;
bool cmp(long int a, long int b){
	return a < b;
}
int main(){
	int n, m, mid;
	long int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%ld",&temp);
		v1.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%ld", &temp);
		v1.push_back(temp);
	}
	mid = (n + m - 1) / 2;
	sort(v1.begin(), v1.end(), cmp);//sort is better than 'insert sort'
	cout << v1[mid];
	return 0;
}