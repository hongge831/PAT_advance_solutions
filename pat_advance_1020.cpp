#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> post, in, pre, level;
int index = 1;
void solve(int postL, int inL, int preL, int n, int index){
	int root, R, L, i;
	if (n == 0) { return; }
	if (n == 1){

		level[index] = pre[preL] = post[postL]; return;
	}
	root = post[postL + n - 1];
	pre[preL] = root;
	level[index] = root;
	for (i = 0; i < n; i++)
	{
		if (in[i + inL] == root)break;
	}
	L = i;
	R = n - i - 1;
	solve(postL, inL, preL + 1, L, 2 * index);
	solve(postL + i, inL + i + 1, preL + i + 1, R, 2 * index + 1);

}

int main(){
	int n, temp;
	cin >> n;
	pre.resize(n);
	level.resize(100000);
	fill(level.begin(), level.end(), -1);
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		post.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		in.push_back(temp);
	}
	solve(0, 0, 0, n, index);
	int cnt = 1, j = 2;
	cout << level[1];
	while (cnt < n-1){
		if (level[j] != -1){
			cout << ' ' << level[j];
			cnt++;
		}j++;
	}
	return 0;
}
