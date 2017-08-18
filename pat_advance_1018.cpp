#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define inf 99999999
#define M 501
vector<int> weigh(M), dis(M), preMark[M], pathTemp, path;
vector<bool> visit(M);
vector<vector<int>> edge(M, vector<int>(M, inf));
int minIn = inf, minOut = inf;
void dfs(int sp){
	if (sp == 0){
		pathTemp.push_back(sp);
		int needOut = 0, takeIn = 0;
		for (int i = pathTemp.size() - 1; i >= 0; i--)
		{
			int id = pathTemp[i];
			if (weigh[id] > 0){
				takeIn += weigh[id];
			}
			else{
				if (takeIn > (0 - weigh[id])){
					takeIn += weigh[id];
				}
				else{
					needOut += ((0 - weigh[id]) - takeIn);
					takeIn = 0;
				}
			}
		}
		if (needOut < minOut){
			minOut = needOut;
			minIn = takeIn;//this point is important
			path = pathTemp;
		}
		else if (needOut == minOut && takeIn<minIn){
			minIn = takeIn;
			path = pathTemp;
		}
		pathTemp.pop_back();
		return;
	}
	/*excellent method should be undstood deeply*/
	pathTemp.push_back(sp);
	for (int i = 0; i < preMark[sp].size(); i++)
	{
		dfs(preMark[sp][i]);
	}
	pathTemp.pop_back();
}
int main(){
	/*data input*/
	int cmax, n, sp, m;
	cin >> cmax >> n >> sp >> m;
	/*How many things are needed for each point.*/
	for (int i = 1; i <= n; i++)//i begins from 1!!!!!!!!!!!!
	{
		cin >> weigh[i];
		weigh[i] = weigh[i] - cmax / 2;
	}
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edge[a][b] = c;
		edge[b][a] = c;
	}
	/*dijkstra begin*/
	fill(visit.begin(), visit.end(), false);
	fill(dis.begin(), dis.end(), inf);
	dis[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		int u = -1, min = inf;
		/*find the min dis_loc*/
		for (int j = 0; j <= n; j++)
		{
			if (visit[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		/*do not find point*/
		if (u == -1){
			break;
		}
		visit[u] = true;
		for (int v = 0; v <= n; v++)
		{
			if (edge[u][v] != inf && visit[v] == false){
				if (dis[v] > dis[u] + edge[u][v]){
					dis[v] = dis[u] + edge[u][v];
					preMark[v].clear();
					preMark[v].push_back(u);
				}
				else if (dis[v] == dis[u] + edge[u][v]){
					preMark[v].push_back(u);
				}
			}
		}
	}
	/*dijkstra end*/
	/*dfs begin*/
	dfs(sp);
	/*final reault is stored in the path*/
	printf("%d ",minOut);
	printf("0");
	for (int i = path.size()-2; i >=0; i--)
	{
		printf("->%d",path[i]);
	}
	printf(" %d", minIn);
	return 0;
}