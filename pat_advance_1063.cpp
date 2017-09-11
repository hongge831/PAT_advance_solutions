#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> st;
vector<set<int>> v;
int main(){
	int n;
	cin >> n;
	/*make set vector*/
	v.resize(n);
	int m, tp;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &tp);
			st.insert(tp);
		}
		v[i] = st;
		st.clear();
	}
	/*begin quering*/
	int k, a, b;
	float ans = 0.0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int nc = 0, nt;
		scanf_s("%d %d", &a, &b);
		nt = v[b - 1].size();
		for (auto it = v[a - 1].begin(); it != v[a - 1].end(); it++)
		{
			if (v[b - 1].find(*it) != v[b - 1].end()){
				nc++;
			}
			else
				nt++;
		}
		ans = 1.0*(nc * 100) / nt;
		printf("%.1f%%\n",ans);
	}
	return 0;
}