#include <stdio.h>
#include <iostream>
#include <algorithm>
#define inf 99999999
#define M 501
using namespace std;
int main(){
	int n, m, c1, c2;//��������������㣬�յ�
	/*����߼������뼯��ĳ�����·�������������ϵ�Ȩ�أ���һ��Ȩ��֮��*/
	int edg[M][M], dis[M], num[M], dotw[M], dotsum[M], path[M];//���ⲻ��Ҫpath������Ϊ����ϵ����path
	bool col[M];//��ʼֵ��true
	cin >> n >> m >> c1 >> c2;
	/*����������ʼ��������*/
	fill(edg[0], edg[0] + M*M, inf);//��ʼ��ͼ�߼�
	fill(dis, dis + M, inf);//��ʼ����С��������
	fill(num, num + M, 0);
	fill(dotw, dotw + M, 0);
	fill(path, path + M, -1);
	fill(col, col + M, false);
	//��ʼ�����Ȩ��
	for (int i = 0; i < n; i++)
	{
		cin >> dotw[i];
	}
	//��ʼ���߾��󣨴�Ȩ�ߣ�
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edg[b][a] = c;
		edg[a][b] = c;
	}
	/*dis,num,dotsum,path��ʼ��*/
	dis[c1] = 0;
	num[c1] = 1;//�Լ����Լ���һ���߷�
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
		//�Ҳ����˳�ѭ�����㷨����
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
				//��������dis��path�����ñ�ֱ��ʹ��num�ж�Ӧ�ĵ�������1����ѡһ���Ƚϴ��dotsum������
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