#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> post, pre;
bool isMirror = false;
void computePost(int root, int tail){
	if (root > tail)
		return;
	int i = root + 1, j = tail;
	if (!isMirror){
		for (; i <= tail && pre[i] < pre[root]; i++);
		for (; j > root && pre[j] >= pre[root]; j--);
	}
	else{
		for (; i <= tail && pre[i] >= pre[root]; i++);
		for (; j > root && pre[j] < pre[root]; j--);
	}
	if (i - j != 1)
		return;
	computePost(root + 1, j);
	computePost(i, tail);
	post.push_back(pre[root]);
}
int main(){
	int n;
	cin >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &pre[i]);
	}
	computePost(0, n - 1);
	if (post.size() != n){
		isMirror = true;
		post.clear();
		computePost(0, n - 1);
	}
	if (post.size() != n){
		printf("NO");
	}
	else{
		printf("YES\n");
		printf("%d", post[0]);
		for (int i = 1; i < n; i++)
		{
			printf(" %d", post[i]);
		}
	}
	return 0;
}