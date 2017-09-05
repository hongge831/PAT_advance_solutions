#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	int rank, weight, index, index0;
};
queue<node> q;
vector<int> wt;
vector<node> v;
bool cmp(node &a, node &b){
	return a.index0 < b.index0;
}
int main(){
	int np, ng;
	cin >> np >> ng;
	wt.resize(np); v.resize(np);
	for (int i = 0; i < np; i++)
	{
		scanf_s("%d", &wt[i]);
	}
	int order;
	for (int i = 0; i < np; i++)
	{
		scanf_s("%d", &order);
		v[i].weight = wt[order];
		v[i].index0 = order;
		v[i].index = i;
		q.push(v[i]);
	}
	while (!q.empty()){
		int size = q.size();
		if (size == 1){
			node temp = q.front();
			v[temp.index].rank = 1;
			break;
		}
		int group = size / ng;
		if (size % ng != 0)
			group += 1;
		node maxNode;
		int max = -1, cnt = 0;
		for (int i = 0; i < size; i++)
		{
			node temp = q.front();
			v[temp.index].rank = group + 1;
			q.pop();
			cnt++;
			if (temp.weight > max){
				max = temp.weight;
				maxNode = temp;
			}
			if (cnt == ng || i == size - 1){
				q.push(maxNode);
				cnt = 0;
				max = -1;
			}
		}

	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < np; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", v[i].rank);
	}

	return 0;
}
