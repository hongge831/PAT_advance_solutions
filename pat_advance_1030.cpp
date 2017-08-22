#include <stdio.h>
#include <iostream>
#include <vector>
#define inf 999999
using namespace std;
int n, m, s, d;
vector<vector<int>> e, cost, pre;
vector<bool> visit;
vector<int> dis;
vector<int> path, pathTemp;
int minCost = inf,totalCost=0;
void dfs(int v){
	if (v == s){
		pathTemp.push_back(v);
		totalCost = 0;
		for (int k = 1; k < pathTemp.size(); k++)
		{
			totalCost += cost[pathTemp[k]][pathTemp[k - 1]];
		}
		if (totalCost < minCost){
			minCost = totalCost;
			path = pathTemp;
		}
		pathTemp.pop_back();
		return;
	}
	pathTemp.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		dfs(pre[v][i]);
	}
	pathTemp.pop_back();
	return;
}
int main(){
	cin >> n >> m >> s >> d;
	e.resize(n, vector<int>(n, inf));
	cost.resize(n, vector<int>(n));
	visit.resize(n);
	pre.resize(n);
	dis.resize(n);
	int a, b, c, q;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> q;
		e[a][b] = e[b][a] = c;
		cost[a][b] = cost[b][a] = q;
	}
	/*dijkstra begin*/
	fill(visit.begin(), visit.end(), false);
	fill(dis.begin(), dis.end(), inf);
	dis[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, minDis = inf;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == false && dis[j] < minDis){
				minDis = dis[j];
				u = j;
			}
		}
		if (u == -1)break;
		visit[u] = true;
		for (int v = 0; v < e[u].size(); v++)
		{
			if (visit[v] == false){
				if (e[u][v] != inf && dis[v] > dis[u] + e[u][v]){
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (e[u][v] != inf && dis[v] == dis[u] + e[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	/*dijkstra end*/
	dfs(d);
	for (int i = path.size()-1; i >=0; i--)
	{
		printf("%d ",path[i]);
	}
	printf("%d %d",dis[d],minCost);
	return 0;
}