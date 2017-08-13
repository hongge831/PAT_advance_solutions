#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> pre;
vector<int> temp;
vector<vector<int>> v;
vector<bool> visit;
int maxHeight = 0;
void init(){
	for (int i = 0; i < pre.size(); i++)
	{
		pre[i] = i;
	}
}
/*union-find sets with path compression*/
int find(int x){
	if (x != pre[x]){
		pre[x] = find(pre[x]);
	}return pre[x];
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if (pre[x] != pre[y]){
		pre[x] = pre[y];
	}
}
/*dfs*/
void dfs(int node,int height){
	if (height > maxHeight){
		temp.clear();
		maxHeight = height;
		temp.push_back(node);
	}
	else if(height ==  maxHeight){
		temp.push_back(node);
	}
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		if (!visit[v[node][i]]){
			dfs(v[node][i], height + 1);
		}
	}
}

int main(){
	int n;
	cin >> n;
	pre.resize(n+1);
	v.resize(n+1);
	init();
	int a, b;
	for (int i = 1; i <= n-1; i++)
	{
		cin >> a >> b;
		merge(a, b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == i){
			sum++;
		}
	}
	if (sum > 1){
		printf("Error: %d components", sum);
	}
	else{
		visit.resize(n+1,false);
		set<int> st;
		dfs(1, 1);
		for (int i = 0; i < temp.size(); i++)
		{
			st.insert(temp[i]);
		}
		int s = temp[0];
		temp.clear(); maxHeight = 0; fill(visit.begin(), visit.end(), false);
		dfs(s, 1);
		for (int i = 0; i < temp.size(); i++)
		{
			st.insert(temp[i]);
		}
		for (set<int>::iterator it = st.begin(); it != st.end(); it++)
			printf("%d\n", *it);
	}

	return 0;
}
