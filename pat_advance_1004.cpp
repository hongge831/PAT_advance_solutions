#include <stdio.h>
#include <iostream>
#include <vector>
#define M 101
using namespace std;
int cnt[M] = {0};
int maxlevel = -1;
vector<vector<int>> v(M);
//DFS algorithm
void dfs(int index, int level){
	if (v[index].size() == 0){
		cnt[level]++;
		maxlevel = maxlevel > level ? maxlevel : level;//remenber the maxlevel when every iterator
		return;
	}
	else{
		for (int i = 0; i < v[index].size(); i++)
		{
			dfs(v[index][i],level+1);
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int index, k, temp;
		cin >> index >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> temp;
			v[index].push_back(temp);
		}
	}
	dfs(1,0);
	cout << cnt[0];
	for (int i = 1; i <= maxlevel; i++)
	{
		cout << ' ' << cnt[i];
	}

	
	return 0;
}



//This is the second method of 1004, this way is litter harder to understand than DFS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#define M 101
using namespace std;
queue<int> q;
vector<vector<int>> v(M);
int level[M] = { 0 }, cnt[M] = { 0 };//level refer to the level of every node;cnt refer to nums of every level
int maxlevel = -1;//the largest level of the tree
int main(){
	//initialize the tree whose node contains its every child
	int n, m;
	cin >> n >> m;
	int index, k, temp;
	for (int i = 0; i < m; i++)
	{
		cin >> index >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> temp;
			v[index].push_back(temp);
		}
	}
	/*BFS start*/
	//initialize the queue
	q.push(1);
	level[1] = 0;
	while (!q.empty()){
		index = q.front();//when reuse the parameter 'index',notice the value of 'index'
		q.pop();
		maxlevel = maxlevel > level[index] ? maxlevel : level[index];//choose the larger level
		//When the node is leaf make arr cnt plus 1
		if (v[index].size() == 0){
			cnt[level[index]]++;
		}
		else{
			for (int j = 0; j < v[index].size(); j++)
			{
				level[v[index][j]] = level[index] + 1;
				q.push(v[index][j]);
			}

		}

	}
	/*BFS end*/
	cout << cnt[0];
	for (int i = 1; i <= maxlevel; i++)
	{
		cout << ' ' << cnt[i];
	}
	return 0;
}
