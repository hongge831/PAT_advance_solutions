/*
这题的输入输出格式理解错误导致代码量巨大，比网上的答案多写了一倍！！！
新手刷PAT总是难免遇到很多问题。
*/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> initStack(int N);
int main(){
	unsigned int M, N, K;//三个变量分别为模拟出栈的大小；序列长度；测试序列大小
	unsigned int j = 0;
	vector<int> popSequence;//用于序列输出
	vector<int>::iterator iter, iter2;
	int temp;
	cin >> M >> N >> K;
	stack<int> outStack, inStack;
	for (unsigned int i = 0; i < N*K; i++)
	{
		cin >> temp;
		popSequence.push_back(temp);
	}
	iter2 = iter = popSequence.begin();
	advance(iter2, N);
	while (iter != popSequence.end()){
		inStack = initStack(N);
		while (!outStack.empty()){
			outStack.pop();
		}
		for (j = 0; j < N; j++)
		{
			//从instack中找数据，找到之前将数据弹入outstack
			if ((outStack.empty() && !inStack.empty() && inStack.top() <= *iter) || !inStack.empty() && inStack.top() <= *iter){
				while (inStack.top() != *iter){
					outStack.push(inStack.top());
					inStack.pop();
				}inStack.pop();
				if (outStack.size() >= M&&iter2 != popSequence.end()){ cout << "NO" << endl; iter = iter2; advance(iter2, N); break; }
				else if (outStack.size() >= M&&iter2 == popSequence.end()){ cout << "NO" << endl; iter = iter2; break; }
				else{ iter++; }
			}//从outstack中找数据，只找栈顶的元素，不是就退出循环
			else{
				if (outStack.top() == *iter){ outStack.pop(); iter++; }
				else if (iter2 == popSequence.end()){ cout << "NO" << endl; iter = iter2; break; }
				else{ cout << "NO" << endl; iter = iter2; advance(iter2, N); break; }
			}
		}
		if (j == N && iter != popSequence.end()){ cout << "YES" << endl; advance(iter2, N); }
		else if (j == N && iter == popSequence.end()){ cout << "YES" << endl; }
	}
	return 0;
}
stack<int> initStack(int N){
	stack<int> initStack;
	for (int i = N; i > 0; i--)initStack.push(i);
	return initStack;
}