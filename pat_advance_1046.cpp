#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
	int n, m;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &v[i]);
		v[i] += v[i - 1];
	}
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &a, &b);
		if (a > b)
			swap(a, b);
		printf("%d\n", min(v[b - 1] - v[a - 1], v[n] - v[b - 1] + v[a - 1]));
	}
	return 0;
}