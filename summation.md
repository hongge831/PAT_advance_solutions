
# PAT_Advance_Practice Summation By YFF #

### [1003. Emergency (25)](https://www.patest.cn/contests/pat-a-practise/1003)


　　这道题是典型的Dijkstra算法的练习，常规思路。最短路径不止一条时需要对路径条数进行另外处理。
```C
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define inf 99999999
#define M 501
using namespace std;
int main(){
	int n, m, c1, c2;//点数，边数，起点，终点
	/*定义边集，距离集，某点最短路径的条数，点上的权重，任一点权重之和*/
	int edg[M][M], dis[M], num[M], dotw[M], dotsum[M], path[M];//此题不需要path，但是为了联系加上path
	bool col[M];//初始值是true
	cin >> n >> m >> c1 >> c2;
	/*根据条件初始化各矩阵*/
	fill(edg[0], edg[0] + M*M, inf);//初始化图边集
	fill(dis, dis + M, inf);//初始化最小距离数组
	fill(num, num + M, 0);
	fill(dotw, dotw + M, 0);
	fill(path, path + M, -1);
	fill(col, col + M, false);
	//初始化点的权重
	for (int i = 0; i < n; i++)
	{
		cin >> dotw[i];
	}
	//初始化边矩阵（带权边）
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edg[b][a] = c;
		edg[a][b] = c;
	}
	/*dis,num,dotsum,path初始化*/
	dis[c1] = 0;
	num[c1] = 1;//自己到自己算一种走法
	dotsum[c1] = dotw[c1];
	while (true)
	{
		int u = -1, min = inf;
		for (int j = 0; j < n; j++)
		{
			if (col[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		//找不到退出循环，算法结束
		if (u == -1)
			break;
		col[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (col[v] == false && edg[u][v] != inf){
				if (dis[u] + edg[u][v] < dis[v]){
					dis[v] = dis[u] + edg[u][v];
					path[v] = u;
					dotsum[v] = dotsum[u] + dotw[v];
					num[v] = num[u];
				}
				//如果相等则dis和path都不用变直接使得num中对应的点数量加1，且选一个比较大的dotsum留下来
				else if (dis[u] + edg[u][v] == dis[v]){
					num[v] = num[u] + num[v];
					if (dotsum[u] + dotw[v] > dotsum[v]){
						dotsum[v] = dotsum[u] + dotw[v];
					}

				}
			}

		}
	}
	cout << num[c2] << ' ' << dotsum[c2];


	return 0;
}
```