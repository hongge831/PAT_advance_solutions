#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void dfs(int i, vector<vector<int>> &v, vector<bool> &isVisit){
	int size = v[1].size();
	isVisit[i] = true;
	for (int j = 0; j < size; j++)
	{
		if (v[i][j] != 0 && isVisit[j] == false){
			dfs(j, v, isVisit);
		}
	}

}
int main(){
	int n, m, k;//n:total numbers of cities;m:numbers of roads;k:numbers of cities should be checked
	cin >> n >> m >> k;
	vector<vector<int>> v(n+1, vector<int>(n+1, 0));
	vector<bool> isVisit(n+1, false);
	int a, b;//the location of city in the map
	/*initialize the map*/
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	/*DFS*/
	int point, cnt = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> point;
		isVisit[point] = true;
		for (int j = 1; j <= n; j++)
		{
			if (isVisit[j] == false){
				dfs(j, v,isVisit);
				cnt++;
			}
		}
		isVisit[point] = false;
		cout << cnt-1 << endl;
		cnt = 0;
		fill(isVisit.begin(), isVisit.end(), false);
	}


	return 0;
}