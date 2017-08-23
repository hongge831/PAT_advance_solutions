#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define M 2005
using namespace std;
map<string, int> sti, ans;
map<int, string> its;
vector<vector<int>> edge(M, vector<int>(M));
vector<int> nodeWeigh(M);
vector<bool> visit;
int NodeNum = 0, head = 0, menberNum = 0, totalWeigh = 0;
int strToInt(string &s){
	if (sti[s] == 0){
		NodeNum++;
		sti[s] = NodeNum;
		its[NodeNum] = s;//errorable:make the its Correspondence
		return sti[s];
	}
	else{
		return sti[s];
	}
}
void dfs(int v, int &head, int &menberNum, int &totalWeigh){
	visit[v] = true;
	/*deal with all variables*/
	menberNum++;
	if (nodeWeigh[v] > nodeWeigh[head]){
		head = v;
	}
	for (int u = 1; u <= NodeNum; u++)
	{
		/*it is worthing noting that edge travesal is different from the node traversal*/
		if (edge[v][u] > 0){
			totalWeigh += edge[v][u];
			edge[u][v] = edge[v][u] = 0;
			if (visit[u] == false)
				dfs(u, head, menberNum, totalWeigh);
		}
	}
}
int main(){
	int n, k;
	cin >> n >> k;
	string s1, s2;
	int w, a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2 >> w;
		/*convert the name to id number*/
		a = strToInt(s1);
		b = strToInt(s2);
		/*add all edge weight to the node*/
		nodeWeigh[a] += w;
		nodeWeigh[b] += w;
		/*sum up two edges into one,then add up all weight*/
		edge[a][b] += w;
		edge[b][a] += w;
	}
	visit.resize(NodeNum + 1, false);
	/*compute every connected_graph's head&menberNum*/
	for (int i = 1; i <= NodeNum; i++)
	{
		head = 0, menberNum = 0, totalWeigh = 0;
		if (visit[i] == false){
			dfs(i, head, menberNum, totalWeigh);
		}
		if (menberNum > 2 && totalWeigh > k){
			ans[its[head]] = menberNum;//stored the result into the ans
		}
	}
	/*print the result*/
	cout << ans.size() << endl;
	for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}