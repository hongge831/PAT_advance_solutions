/*
��������������ʽ�������´������޴󣬱����ϵĴ𰸶�д��һ��������
����ˢPAT�������������ܶ����⡣
*/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> initStack(int N);
int main(){
	unsigned int M, N, K;//���������ֱ�Ϊģ���ջ�Ĵ�С�����г��ȣ��������д�С
	unsigned int j = 0;
	vector<int> popSequence;//�����������
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
			//��instack�������ݣ��ҵ�֮ǰ�����ݵ���outstack
			if ((outStack.empty() && !inStack.empty() && inStack.top() <= *iter) || !inStack.empty() && inStack.top() <= *iter){
				while (inStack.top() != *iter){
					outStack.push(inStack.top());
					inStack.pop();
				}inStack.pop();
				if (outStack.size() >= M&&iter2 != popSequence.end()){ cout << "NO" << endl; iter = iter2; advance(iter2, N); break; }
				else if (outStack.size() >= M&&iter2 == popSequence.end()){ cout << "NO" << endl; iter = iter2; break; }
				else{ iter++; }
			}//��outstack�������ݣ�ֻ��ջ����Ԫ�أ����Ǿ��˳�ѭ��
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