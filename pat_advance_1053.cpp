#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, target;
struct node{
	int w;
	vector<int> child;
};
vector<node> v;
vector<int> path;

bool cmp(int a,int b){
	return v[a].w > v[b].w;
}//sort by the node weight
void dfs(int index, int sum){
	//menmory the every path who is satisfy the situation(same as 1018 & 1030)
	path.push_back(index);
	if (sum > target){
		path.pop_back();
		return;
	}
	if (sum == target){
		if (v[index].child.size() != 0){
			path.pop_back();
			return;
		}
		for (int i = 0; i < path.size(); i++)
		{
			//make code shorter
			printf("%d%c", v[path[i]].w, i != path.size() - 1 ? ' ' : '\n');
		}
		path.pop_back();
		return;
	}
	for (int i = 0; i < v[index].child.size(); i++)
	{
		int nodeTemp = v[index].child[i];
		dfs(nodeTemp, sum + v[nodeTemp].w);//the second parameter is errorable
	}
	path.pop_back();
}
int main(){
	/*data input and tree construction*/
	scanf_s("%d %d %d", &n, &m, &target);
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &v[i].w);
	}
	//construct the tree by the lined list way
	int k, nodeId, childId;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &nodeId, &k);
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", &childId);
			v[nodeId].child.push_back(childId);
		}
		sort(v[nodeId].child.begin(),v[nodeId].child.end(),cmp);
	}
	/*dfs begin*/
	//the result output is in the dfs function
	dfs(0, v[0].w);

	return 0;
}