#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
void initArray(int *pre, int *in, int n);
void solution(int *pre, int *in, int *post, int n);
void printResult(int *post, int n);
int main(){
	int n;
	cin >> n;
	//动态分配存储空间
	int *pre = (int*)malloc(n*sizeof(int));
	int *in = (int*)malloc(n*sizeof(int));
	int *post = (int*)malloc(n*sizeof(int));
	//初始化先序和中序遍历的结果数组
	initArray(pre, in, n);
	//递归分而治之得到后序遍历结果
	solution(pre, in, post, n);
	//打印结果
	printResult(post, n);
	free(pre); free(in); free(post);
	return 0;
}

void initArray(int *pre, int *in, int n){
	string s;
	int j, k;
	stack<int> stk;
	j = k = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> s;
		if (s == "Push"){
			cin >> pre[j];
			stk.push(pre[j]);
			j++;
		}
		else if (s == "Pop"){
			in[k++] = stk.top();
			stk.pop();
		}
	}
}

void solution(int *pre, int *in, int *post, int n){
	if (n == 0) return;
	if (n == 1){
		post[n-1] = pre[0];
		return;
	}
	int root = pre[0];
	int i;
	for (i = 0; i < n; i++)
	{
		if (root == in[i]) break;
	}
	int nLeft = i;
	int nRight = n - i - 1;
	post[n - 1] = root;
	solution(pre + 1, in, post, nLeft);
	solution(pre + i + 1, in + i + 1, post + i, nRight);
}
void printResult(int *post, int n){
	for (int i = 0; i < n-1; i++)
	{
		cout << post[i] << " ";
	}
	cout << post[n - 1];
}