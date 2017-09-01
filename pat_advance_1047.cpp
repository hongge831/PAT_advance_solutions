#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<string>> v;
bool cmp(string &a, string &b){
	return a < b;
}
int main(){
	int n, k;
	cin >> n >> k;
	v.resize(k + 1);
	string str;
	str.resize(4);
	int num, temp;
	/*data input*/
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		scanf_s("%d", &num);
		for (int j = 0; j < num; j++)
		{
			scanf_s("%d", &temp);
			v[temp].push_back(str);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++)
		{
			printf("%s\n", v[i][j].c_str());
		}
	}

	return 0;
}